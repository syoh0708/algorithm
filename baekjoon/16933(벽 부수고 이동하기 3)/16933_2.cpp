#include <bits/stdc++.h>

using namespace std;

int n, m, k;
bool board[1005][1005];
bool dist[1005][1005][2][12];
int dx[5] = {1, 0, -1, 0, 0};
int dy[5] = {0, 1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;

        for (int j = 0; j < m; j++) {
            if (s[j] == '1') board[i][j] = true;
        }
    }

    // x, y, d, c, day
    queue<tuple<int, int, int, int, int>> q;

    q.push({0, 0, 1, 0, 1});
    dist[0][0][1][0] = 1;

    while (!q.empty()) {
        int x, y, d, c, day;

        tie(x, y, d, c, day) = q.front(); q.pop();

        if (x == n - 1 && y == m - 1) {
            cout << d;
            return 0;
        }

        for (int dir = 0; dir < 5; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nday = 1 - day;
            int nc = c;
            int nd = d + 1;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dir != 4 && !day && board[nx][ny]) continue;
            if (dir != 4 && board[nx][ny]) nc++;
            if (nc > k || dist[nx][ny][nday][nc]) continue;

            dist[nx][ny][nday][nc] = true;
            q.push({nx, ny, nd, nc, nday});
        }
    }
    
    cout << -1;
}
