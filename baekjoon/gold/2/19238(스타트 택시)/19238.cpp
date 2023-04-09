#include <bits/stdc++.h>

using namespace std;

int n, m, f, cx, cy;
int board[22][22];
pair<int, int> dest[405];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

tuple<int, int, int> find_user() {
    if (board[cx][cy] > 0) return {cx, cy, 0};

    int ux = 100, uy = 100, ud = 1'000'000'000;
    queue<tuple<int, int, int>> q;
    bool vis[22][22] = {};

    q.push({cx, cy, 0});
    vis[cx][cy] = true;
    
    while (!q.empty()) {
        int x, y, d;

        tie(x, y, d) = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] == -1 || vis[nx][ny]) continue;

            vis[nx][ny] = true;
            if (board[nx][ny] > 0 && d + 1 <= ud && (nx < ux || (nx == ux && ny < uy))) {
                ud = d + 1;
                ux = nx;
                uy = ny;
            }
            q.push({nx, ny, d + 1});
        }
    }

    cx = ux;
    cy = uy;

    return {ux, uy, ud};
}

bool ride() {
    int ux, uy, ud, u, dist = 0;
    tie(ux, uy, ud) = find_user();
    u = board[ux][uy];
    board[ux][uy] = 0;

    if (f <= ud) return false;

    f -= ud;

    int tmp[22][22] = {};
    queue<pair<int, int>> q;
    q.push({cx, cy});
    bool found = false;

    while (!found && !q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] == -1 || tmp[nx][ny]) continue;

            tmp[nx][ny] = tmp[x][y] + 1;
            q.push({nx, ny});
            if (nx == dest[u].first && ny == dest[u].second) {
                dist = tmp[nx][ny];
                cx = nx;
                cy = ny;
                found = true;
                break;
            }
        }
    }


    if (!found || f < dist) return false;

    f += dist;

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> f;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];

            board[i][j] = -board[i][j];
        }
    }

    cin >> cx >> cy;
    cx--; cy--;

    for (int i = 1; i <= m; i++) {
        int sx, sy, dx, dy;

        cin >> sx >> sy >> dx >> dy;

        board[sx - 1][sy - 1] = i;
        dest[i] = {dx - 1, dy - 1};
    }

    while (m--) {
        if (!ride()) {
            cout << -1;
            return 0;
        }
    }

    cout << f;
}
