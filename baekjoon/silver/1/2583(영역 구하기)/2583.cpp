#include <bits/stdc++.h>

using namespace std;

bool visited[101][101];
int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m, n, k;
    vector<int> area;

    cin >> m >> n >> k;

    while (k--) {
        int x1, y1, x2, y2;

        cin >> y1 >> x1 >> y2 >> x2;

        for (int i = x1; i < x2; i++) {
            for (int j = y1; j < y2; j++) {
                visited[i][j] = true;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;

            queue<pair<int, int>> q;
            int a = 0;

            q.push({i, j});
            visited[i][j] = true;

            while (!q.empty()) {
                int x, y, nx, ny;
                pair<int, int> cur = q.front(); q.pop();
                x = cur.first; y = cur.second;
                a++;

                for (int dir = 0; dir < 4; dir++) {
                    nx = x + dx[dir];
                    ny = y + dy[dir];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (visited[nx][ny]) continue;
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }

            area.push_back(a);
        }
    }

    sort(area.begin(), area.end());

    cout << area.size() << '\n';
    for (int a : area) {
        cout << a << ' ';
    }
}
