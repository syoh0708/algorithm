#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char arr[101][101];
bool visited[101][101];

int bfs(int i, int j, int n, bool blind) {
    queue<pair<int, int>> q;

    q.push({i, j});
    visited[i][j] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int mv = 0; mv < 4; mv++) {
            int nx = cur.first + dx[mv];
            int ny = cur.second + dy[mv];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (!visited[nx][ny]) {
                if (blind) {
                    if ((arr[cur.first][cur.second] == 'B') != (arr[nx][ny] == 'B')) continue;
                } else {
                    if (arr[cur.first][cur.second] != arr[nx][ny]) continue;
                }

                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, a = 0, b = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                a += bfs(i, j, n, false);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        fill(visited[i], visited[i] + n, 0);
    }

        for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                b += bfs(i, j, n, true);
            }
        }
    }

    cout << a << ' ' << b;
}
