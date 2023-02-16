#include <bits/stdc++.h>

using namespace std;

string board[12];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool step() {
    bool vis[12][6] = {};
    bool combo = false;

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (vis[i][j]) continue;

            vis[i][j] = true;

            if (board[i][j] == '.') continue;

            queue<pair<int, int>> q;
            vector<pair<int, int>> v;
            char color = board[i][j];
            int cnt = 1;

            q.push({i, j});
            v.push_back({i, j});

            while (!q.empty()) {
                pair<int, int> cur = q.front(); q.pop();
            
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
            
                    if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
                    if (board[nx][ny] != color || vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                    v.push_back({nx, ny});
                    cnt++;
                }
            }

            if (cnt > 3) {
                combo = true;
                for (auto p : v) {
                    board[p.first][p.second] = '.';
                }
            }
        }
    }

    for (int j = 0; j < 6; j++) {
        string s = "";
        for (int i = 11; i >= 0; i--) {
            if (board[i][j] != '.') s += board[i][j];
        }

        while (s.size() < 12) {
            s += '.';
        }

        for (int i = 0; i < 12; i++) {
            board[11 - i][j] = s[i];
        }
    }

    return combo;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;

    for (int i = 0; i < 12; i++) {
        cin >> board[i];
    }

    while (step()) ans++;

    cout << ans;
}
