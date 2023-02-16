#include <bits/stdc++.h>

using namespace std;

int n, m, x, y;
int board[20][20];
int dice[6]; // u r d l f b

void roll(int dir) {
    if (dir == 1) {
        if (y == m - 1) return;

        int tmp = dice[3];
        
        for (int i = 3; i > 0; i--) {
            dice[i] = dice[i - 1];
        }
        dice[0] = tmp;
        y++;
    } else if (dir == 2) {
        if (y == 0) return;

        int tmp = dice[0];

        for (int i = 0; i < 3; i++) {
            dice[i] = dice[i + 1];
        }
        dice[3] = tmp;
        y--;
    } else if (dir == 3) {
        if (x == 0) return;
        
        int tmp = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[2];
        dice[2] = dice[5];
        dice[5] = tmp;
        x--;

    } else { // dir == 4
        if (x == n - 1) return;

        int tmp = dice[0];
        dice[0] = dice[5];
        dice[5] = dice[2];
        dice[2] = dice[4];
        dice[4] = tmp;
        x++;
    }

    if (!board[x][y]) {
        board[x][y] = dice[2];
    } else {
        dice[2] = board[x][y];
        board[x][y] = 0;
    }

    cout << dice[0] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, op;

    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    while (k--) {
        cin >> op;

        roll(op);
    }
}
