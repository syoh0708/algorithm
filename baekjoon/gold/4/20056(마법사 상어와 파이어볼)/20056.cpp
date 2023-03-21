#include <bits/stdc++.h>

using namespace std;

int n, f, k, ans;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> f >> k;
    queue<tuple<int, int, int, int, int>> q;

    while (f--) {
        int r, c, m, s, d; cin >> r >> c >> m >> s >> d;
        q.push({r - 1, c - 1, m, s, d});
    }

    for (int i = 0; i < k; i++) {
        int board[51][51] = {};
        int dir[51][51] = {};
        int speed[51][51] = {};
        int cnt[51][51] = {};
        int diff_d[51][51] = {};

        int r, c, m, s, d;
        while (!q.empty()) {
            tie(r, c, m, s, d) = q.front(); q.pop();

            int nr = (r + dx[d] * (s % n) + n) % n;
            int nc = (c + dy[d] * (s % n) + n) % n;
            board[nr][nc] += m;
            speed[nr][nc] += s;
            if (cnt[nr][nc] > 0 && (dir[nr][nc] + d) % 2) diff_d[nr][nc] = 1;
            dir[nr][nc] = d;
            cnt[nr][nc]++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!cnt[i][j]) continue;
                if (cnt[i][j] == 1) {
                    q.push({i, j, board[i][j], speed[i][j], dir[i][j]});
                } else {
                    if (board[i][j] / 5 == 0) continue;
                    for (int k = 0; k < 4; k++) q.push({i, j, board[i][j] / 5, speed[i][j] / cnt[i][j], 2 * k + diff_d[i][j]});
                }
            }
        }
    }

    while (!q.empty()) {
        int r, c, m, s, d;
        tie(r, c, m, s, d) = q.front(); q.pop();
        ans += m;
    }

    cout << ans;
}
