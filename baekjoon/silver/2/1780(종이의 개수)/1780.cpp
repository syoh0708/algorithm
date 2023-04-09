#include <bits/stdc++.h>

using namespace std;

int n;
int board[2200][2200];

bool same_number(int r, int c, int k) {
    int num = board[r][c];

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            if (num != board[r + i][c + j]) return false;

    return true;
}

tuple<int, int, int> solve(int r, int c, int k) {
    int x = 0, y = 0, z = 0;

    if (k == 1 || same_number(r, c, k)) {
        x = (board[r][c] == -1);
        y = (board[r][c] == 0);
        z = (board[r][c] == 1);

        return {x, y, z};
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int cx, cy, cz;

            tie(cx, cy, cz) = solve(r + k * i / 3, c + k * j / 3, k / 3);

            x += cx;
            y += cy;
            z += cz;
        }
    }

    return {x, y, z};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    int x, y, z;

    tie(x, y, z) = solve(0, 0, n);

    cout << x << '\n' << y << '\n' << z;
}
