#include <bits/stdc++.h>

using namespace std;

int n, m;
int g[300][300];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool melt() {
    bool is_melt = false;

    int melt[300][300] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j]) {
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (g[nx][ny] == 0) {
                        melt[i][j]++;
                        is_melt = true;
                    }
                }
            }
        }
    }

    if (is_melt) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                g[i][j] = max(0, g[i][j] - melt[i][j]);
            }
        }
    }

    return is_melt;
}

int bfs() {
    int glacier_count = 0;
    bool vis[300][300] = {};
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] && !vis[i][j]) {
                vis[i][j] = true;
                glacier_count++;

                q.push({i, j});

                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (g[nx][ny] == 0 || vis[nx][ny]) continue;

                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    return glacier_count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    for (int y = 0; y <= 10000; y++) {
        if (bfs() > 1) {
            cout << y;
            return 0;
        }
        if (!melt()) break;
    }

    cout << 0;
}
