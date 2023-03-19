#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
vector<int> curves[11];
bool b[101][101];

void fill_curves() {
    curves[0].push_back(0);

    for (int i = 1; i < 11; i++) {
        curves[i] = curves[i - 1];
        int sz = curves[i - 1].size();
        for (int j = sz - 1; j >= 0; j--) {
            curves[i].push_back((curves[i - 1][j] + 1) % 4);
        }
    }
}

void draw_curves(int x, int y, int d, int g) {
    b[x][y] = true;

    for (int dir : curves[g]) {
        x += dx[(dir + d) % 4];
        y += dy[(dir + d) % 4];
        b[x][y] = true;
    }
}

int count_square() {
    int ans = 0;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (b[i][j] && b[i + 1][j] && b[i][j + 1] && b[i + 1][j + 1]) ans++;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;

    fill_curves();

    while (n--) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        draw_curves(x, y, d, g);
    }

    cout << count_square();
}
