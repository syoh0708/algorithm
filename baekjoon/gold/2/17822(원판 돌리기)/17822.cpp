#include <bits/stdc++.h>

using namespace std;

int n, m, t, ans;
int b[55][55];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool same_neighbor(int x, int y) {
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = (y + dy[dir] + m) % m;

        if (nx < 0 || nx >= n) continue;
        if (b[nx][ny] == b[x][y]) return true;
    }

    return false;    
}

void rotate(int x, int d, int k) {
    if (d) k = m - k;

    for (int i = 0; i < n; i++) {
        if (!((i + 1) % x)) {
            int tmp[55] = {};

            for (int j = 0; j < m; j++) tmp[(j + k) % m] = b[i][j];
            for (int j = 0; j < m; j++) b[i][j] = tmp[j];
        }
    }

    bool vis[55][55] = {};
    bool erased = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            if (!same_neighbor(i, j) || !b[i][j]) {
                vis[i][j] = true;
                continue;
            }

            int cur = b[i][j];
            queue<pair<int, int>> q;

            erased = true;
            vis[i][j] = true;
            q.push({i, j});
            b[i][j] = 0;

            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = (y + dy[dir] + m) % m;

                    if (nx < 0 || nx >= n) continue;
                    if (b[nx][ny] != cur || vis[nx][ny]) continue;

                    b[nx][ny] = 0;
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }           
            }
        }
    }

    if (!erased) {
        int cnt = 0, sum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (b[i][j]) {
                    cnt++;
                    sum += b[i][j];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (b[i][j]) {
                    if (b[i][j] * cnt > sum) b[i][j]--;
                    else if (b[i][j] * cnt < sum) b[i][j]++;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> b[i][j];

    while (t--) {
        int x, d, k; cin >> x >> d >> k;

        rotate(x, d, k);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans += b[i][j];

    cout << ans;
}
