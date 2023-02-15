#include <bits/stdc++.h>

using namespace std;

bool board[50][50], vis[50][50];
int n, m, r, c, d, ans, i;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool movable(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m) && !board[x][y];
}

bool cleanable(int x, int y) {
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (movable(nx, ny) && !vis[nx][ny]) return true; 
    }

    return false;
}

bool clean() {
    if (!vis[r][c]) {
        ans++;
        vis[r][c] = true;
    }

    if (cleanable(r, c)) {
        while (1) {
            d = (d + 3) % 4;
            int nx = r + dx[d];
            int ny = c + dy[d];
            if (movable(nx, ny) && !vis[nx][ny]) {
                r = nx;
                c = ny;
                break;
            }
        }
    } else {
        if (!movable(r - dx[d], c - dy[d])) return false;
        r -= dx[d];
        c -= dy[d];
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r >> c >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    while (clean()) {}
    
    cout << ans;
}
