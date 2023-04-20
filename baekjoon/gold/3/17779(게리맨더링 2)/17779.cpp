#include <bits/stdc++.h>

using namespace std;

int n, ans = 1e9;
int board[4][22][22];

int solve(int x, int y, int d1, int d2) {
    int mn = 1e9, mx = 0;
    bool vis[4][22][22] = {};

    int p = 0;

    for (int i = x; i <= x + d1 + d2; i++) {
        for (int j = y + abs(i - x - d1) - d1; j <= y -abs(i - x - d2) + d2; j++) {
            p += board[0][i][j];
            vis[0][i][j] = true;
            vis[1][n + 1 - j][i] = true;
            vis[2][n + 1 - i][n + 1 - j] = true;
            vis[3][j][n + 1 - i] = true;
        }
    }

    mn = min(mn, p);
    mx = max(mx, p);
    int ex[4] = {x + d1 - 1, n - y,  n - x - d2,     y - 1 - d1 + d2};
    int ey[4] = {y,          x + d2, n + 1 - y + d1 - d2, n + 1 - x - d1};


    for (int k = 0; k < 4; k++) {
        p = 0;
        for (int i = 1; i <= ex[k]; i++) {
            for (int j = 1; j <= ey[k]; j++) {
                if (vis[k][i][j]) break;

                p += board[k][i][j];
            }
        }

        mn = min(mn, p);
        mx = max(mx, p);
    }

    return mx - mn;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[0][i][j];
            board[1][n + 1 - j][i] = board[0][i][j];
            board[2][n + 1 - i][n + 1 - j] = board[0][i][j];
            board[3][j][n + 1 - i] = board[0][i][j];
        }
    }

    for (int  d1 = 1; d1 < n - 1; d1++)
        for (int d2 = 1; d1 + d2 < n; d2++)
            for (int x = 1; x + d1 + d2 <= n; x++)
                for (int y = d1 + 1; y <= n - d2; y++)
                    ans = min(ans, solve(x, y, d1, d2));
    
    cout << ans;
}
