#include <bits/stdc++.h>

using namespace std;

int n, m, p;
int s[10];
int cnt[10];
string board[1005];
bool vis[1005][1005];
queue<tuple<int, int, int>> q[10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> p;

    for (int i = 1; i <= p; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> board[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isdigit(board[i][j])) {
                q[board[i][j] - '0'].push({i, j, 0});
                cnt[board[i][j] - '0']++;
                vis[i][j] = true;   
            } else if (board[i][j] == '#') {
                vis[i][j] = true;
            }
        }
    }

    int round = 0;
    
    while (1) {
        bool extended = false;
        for (int i = 1; i <= p; i++) {
            while (!q[i].empty()) {
                int x, y, d;

                tie(x, y, d) = q[i].front();

                if (d / s[i] > round) break;

                q[i].pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny]) continue;

                    vis[nx][ny] = true;
                    q[i].push({nx, ny, d + 1});
                    cnt[i]++;
                    extended = true;
                }
                
            }
        }

        if (!extended) break;
        round++;
    }

    for (int i = 1; i <= p; i++) cout << cnt[i] << ' ';
}
