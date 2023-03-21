#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
int board[51][51];
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};


vector<pair<int, int>> move(vector<pair<int, int>>& clouds, int d, int s) {
    vector<pair<int, int>> v;

    for (auto cloud : clouds) {
        v.push_back({(cloud.first + dx[d] * s + n) % n, (cloud.second + dy[d] * s + n) % n});
    }

    return v;
}

void copy_water(pair<int, int> cloud) {
    int x = cloud.first;
    int y = cloud.second;

    if (x > 0 && y > 0 && board[x - 1][y - 1]) board[x][y]++;
    if (x > 0 && y < n - 1 && board[x - 1][y + 1]) board[x][y]++;
    if (x < n - 1 && y > 0 && board[x + 1][y - 1]) board[x][y]++;
    if (x < n - 1 && y < n - 1 && board[x + 1][y + 1]) board[x][y]++;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> board[i][j];
    }

    vector<pair<int, int>> clouds = {{n - 1, 0}, {n - 1, 1}, {n - 2, 0}, {n - 2, 1}};
    while (m--) {
        int d, s; cin >> d >> s;

        clouds = move(clouds, d - 1, s % n);
        for (auto cloud : clouds) board[cloud.first][cloud.second]++;
        for (auto cloud : clouds) copy_water(cloud);
        bool tmp_board[51][51] = {};
        for (auto cloud : clouds) tmp_board[cloud.first][cloud.second] = true;

        clouds.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] > 1 && !tmp_board[i][j]) {
                    board[i][j] -= 2;
                    clouds.push_back({i, j});
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) ans += board[i][j];
    }

    cout << ans;
}
