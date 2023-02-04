#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, m, n, k, i, j;

    cin >> t;

    while (t--) {
        cin >> m >> n >> k;
        bool arr[50][50] = {};
        int ans = 0;

        while (k--) {
            cin >> i >> j;

            arr[i][j] = 1;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j]) {
                    ans++;
                    arr[i][j] = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    while (!q.empty()) {
                        pair<int, int> cur = q.front(); q.pop();

                        for (int dir = 0; dir < 4; dir++) {
                            int x = cur.first + dx[dir];
                            int y = cur.second + dy[dir];

                            if (x < 0 || x >= m || y < 0 || y >= n) continue;
                            if (arr[x][y]) {
                                arr[x][y] = 0;
                                q.push({x, y});
                            }
                        }
                    }
                }
            }
        }

        cout << ans << '\n';
    }
}
