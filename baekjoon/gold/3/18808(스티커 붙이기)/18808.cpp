#include <bits/stdc++.h>

using namespace std;

bool st[100][4][10][10];
pair<int, int> sz[100];
bool laptop[40][40];
int n, m, k;

bool stickable(int s_idx, int r_idx, int r, int c) {
    pair<int, int> s = sz[s_idx];
    int w = r_idx % 2 ? s.first : s.second;
    int h = r_idx % 2 ? s.second : s.first;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (st[s_idx][r_idx][i][j] && laptop[r + i][c + j]) return false;
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (st[s_idx][r_idx][i][j]) laptop[r + i][c + j] = true;
        }
    }

    return true;
}

void func(int i) {
    pair<int, int> s = sz[i];

    for (int rotate_idx = 0; rotate_idx < 4; rotate_idx++) {
        int w = rotate_idx % 2 ? s.first : s.second;
        int h = rotate_idx % 2 ? s.second : s.first;

        for (int k = 0; k + h <= n; k++){
            for (int l = 0; l + w <= m; l++) {
                if (stickable(i, rotate_idx, k, l)) return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int h, w; cin >> h >> w;
        sz[i] = {h, w};

        for (int j = 0; j < h; j++) {
            for (int l = 0; l < w; l++) {
                bool x; cin >> x;

                if (x) {
                    st[i][0][j][l] = true;
                    st[i][1][l][h - 1 - j] = true;
                    st[i][2][h - 1 - j][w - 1 - l] = true;
                    st[i][3][w - 1 - l][j] = true;
                }

            }    
        }
    }

    for (int i = 0; i < k; i++) func(i);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += laptop[i][j];
        }
    }

    cout << ans;
}
