#include <bits/stdc++.h>

using namespace std;

int r, c, t, up, down, ans;
int board[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> t;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
            if (board[i][j] == -1) down = i;
        }
    }
    up = down - 1;

    while (t--) {
        int left[51][51] = {};
        int diff[51][51] = {};

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] < 5) continue;

                int dust = board[i][j] / 5;

                for (int dir = 0; dir < 4; dir++){
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    
                    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                    if (board[nx][ny] == -1) continue;

                    left[i][j] -= dust;
                    diff[nx][ny] += dust;
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) board[i][j] += (left[i][j] + diff[i][j]);
        }

        for (int i = up - 1; i > 0; i--) board[i][0] = board[i - 1][0];
        for (int j = 0; j < c - 1; j++) board[0][j] = board[0][j + 1];
        for (int i = 0; i < up; i++) board[i][c - 1] = board[i + 1][c - 1];
        for (int j = c - 1; j > 0; j--) board[up][j] = board[up][j - 1];
        board[up][1] = 0;

        for (int i = down + 1; i < r - 1; i++) board[i][0] = board[i + 1][0];
        for (int j = 0; j < c - 1; j++) board[r - 1][j] = board[r - 1][j + 1];
        for (int i = r - 1; i > down; i--) board[i][c - 1] = board[i - 1][c - 1];
        for (int j = c - 1; j > 0; j--) board[down][j] = board[down][j - 1];
        board[down][1] = 0;
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ans += board[i][j];
        }
    }

    cout << ans + 2;
}
