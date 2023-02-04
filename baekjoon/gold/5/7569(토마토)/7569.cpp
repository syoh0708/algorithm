#include <bits/stdc++.h>

using namespace std;

int t[101][101][101];
int dist[101][101][101];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m, n, h, a, ret = 0;
    queue<tuple<int, int, int>> q;

    cin >> m >> n >> h;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            fill(dist[i][j], dist[i][j] + m, 1000);
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++)
            {
                cin >> a;

                t[i][j][k] = a;
                if (a == -1) dist[i][j][k] = -1;
                if (a == 1) {
                    q.push({i, j, k});
                    dist[i][j][k] = 0;
                }
            }
        }
    }

    while (!q.empty()) {
        int x, y, z, nx, ny, nz;
        tuple<int, int, int> cur = q.front(); q.pop();
        tie(x, y, z) = cur;
        
        for (int dir = 0; dir < 6; dir++) {
            nx = x + dx[dir];
            ny = y + dy[dir];
            nz = z + dz[dir];

            if (nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m) continue;
            if (dist[nx][ny][nz] == 1000) {
                dist[nx][ny][nz] = dist[x][y][z] + 1;
                q.push({nx, ny, nz});
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            ret = max(*max_element(dist[i][j], dist[i][j] + m), ret);
        }
    }

    if (ret == 1000) {
        cout << -1;
    } else {
        cout << ret;
    }
}
