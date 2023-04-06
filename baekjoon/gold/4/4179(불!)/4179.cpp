#include <bits/stdc++.h>

using namespace std;

int r, c;
string board[1005];
int fire[1005][1005];
bool fvis[1005][1005];
int jh[1005][1005];
bool jvis[1005][1005];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        cin >> board[i];
        fill(fire[i], fire[i] + c, 1000000);
    }

    queue<pair<int, int>> fq;
    queue<pair<int, int>> jq;
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 'F') {
                fq.push({i, j});
                fvis[i][j] = true;
                fire[i][j] = 0;
            } else if (board[i][j] == 'J') {
                jq.push({i, j});
                jvis[i][j] = true;
            }
        }
    }

    while (!fq.empty()) {
        int x, y;
        
        tie(x, y) = fq.front(); fq.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (board[nx][ny] == '#' || fvis[nx][ny]) continue;

            fvis[nx][ny] = true;
            fire[nx][ny] = fire[x][y] + 1;
            fq.push({nx, ny});
        }
    }

    while (!jq.empty()) {
        int x, y;

        tie(x, y) = jq.front(); jq.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                cout << jh[x][y] + 1;
                return 0;
            }
            if (board[nx][ny] == '#' || jvis[nx][ny] || jh[x][y] + 1 >= fire[nx][ny]) continue;

            jvis[nx][ny] = true;
            jh[nx][ny] = jh[x][y] + 1;
            jq.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}
