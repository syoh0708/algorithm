#include <bits/stdc++.h>

using namespace std;

int p[50][50];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l, r;

    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
        }
    }

    int d = 0;

    for (; d <= 2000; d++) {
        bool vis[50][50] = {};
        bool changed = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j]) continue;

                int union_count = 1, population = p[i][j];
                queue<pair<int, int>> q;
                queue<pair<int, int>> tmp;

                q.push({i, j});
                tmp.push({i, j});
                vis[i][j] = true;

                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();
                
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                        int pop_diff = abs(p[cur.first][cur.second] - p[nx][ny]);

                        if (pop_diff < l || pop_diff > r || vis[nx][ny]) continue;
                        vis[nx][ny] = true;
                        changed = true;
                        union_count++;
                        population += p[nx][ny];
                        q.push({nx, ny});
                        tmp.push({nx, ny});
                    }
                }

                if (union_count > 1) {
                    while (!tmp.empty()) {
                        pair<int, int> cur = tmp.front(); tmp.pop();

                        p[cur.first][cur.second] = population / union_count;
                    }
                }
            }
        }

        if (!changed) break;
    }

    cout << d;
}
