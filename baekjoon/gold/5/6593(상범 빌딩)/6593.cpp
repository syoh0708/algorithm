#include <bits/stdc++.h>

using namespace std;

char board[30][30][30];
int dist[30][30][30];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int l, r, c, ei, ej, ek;
    queue<tuple<int, int, int>> q;

    while (1) {
        bool escaped = false;

        cin >> l >> r >> c;

        if (l == 0 && r == 0 && c == 0) break;

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                fill(dist[i][j], dist[i][j] + c, -1);
            }
        }

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    char ch; cin >> ch;

                    if (ch == 'S') {
                        q.push({i, j, k});
                        dist[i][j][k] = 0;
                    }
                    if (ch == 'E') {
                        ei = i;
                        ej = j;
                        ek = k;
                    }
                    board[i][j][k] = ch;
                }
            }
        }

        while (!q.empty()) {
            int ci, cj, ck;
            tie(ci, cj, ck) = q.front(); q.pop();

            for (int dir = 0; dir < 6; dir++) {
                int ni = ci + dx[dir];
                int nj = cj + dy[dir];
                int nk = ck + dz[dir];

                if (ni < 0 || ni >= l || nj < 0 || nj >= r || nk < 0 || nk >= c) continue;
                if (board[ni][nj][nk] == '#' || dist[ni][nj][nk] >= 0) continue;

                dist[ni][nj][nk] = dist[ci][cj][ck] + 1;
                q.push({ni, nj, nk});
                if (ei == ni && ej == nj && ek == nk) {
                    cout << "Escaped in " << dist[ni][nj][nk] << " minute(s).\n";
                    escaped = true;
                    break;
                }
            }
        }

        if (!escaped) cout << "Trapped!\n";
    }
}
