#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

bool vis[1000][1000];
int dist[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> q;
    int m, n, a, ans = 0;
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a;

            if (a == 1) {
                vis[i][j] = true;
                q.push({i, j});
                dist[i][j] = 0;
            } else if (a == 0) {
                dist[i][j] = -1;
            } else {
                vis[i][j] = true;
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny]) continue;

            vis[nx][ny] = true;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == -1) {
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }

    cout << ans;
}
