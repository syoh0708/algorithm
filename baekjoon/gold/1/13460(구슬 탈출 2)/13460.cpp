#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;
int n, m, mn = MAX;
int RX, RY, BX, BY, OX, OY;
int rx, ry, bx, by, ox, oy;
int dir;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string b[11];

int move(int dir) {
    int tx = rx, ty = ry;
    bool same_dir = false;

    while (tx >= 0 && tx < n && ty >= 0 && ty < m 
            && b[tx][ty] != '#'
            && b[tx][ty] != 'O') {
        if (tx == bx && ty == by) same_dir = true;
        tx += dx[dir];
        ty += dy[dir];
    }


    if (same_dir) {
        int nx = bx + dx[dir];
        int ny = by + dy[dir];

        while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (b[nx][ny] == 'O') return 0;
            if (b[nx][ny] == '#') break;

            bx = nx;
            by = ny;
            nx = bx + dx[dir];
            ny = by + dy[dir];
        }

        nx = rx + dx[dir];
        ny = ry + dy[dir];

        while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (b[nx][ny] == '#' || (nx == bx && ny == by)) break;

            rx = nx;
            ry = ny;
            nx = rx + dx[dir];
            ny = ry + dy[dir];
        }

        return 1;
    } else {
        int nx = rx + dx[dir];
        int ny = ry + dy[dir];
        bool done = false;

        while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (b[nx][ny] == '#') break;
            if (b[nx][ny] == 'O') {
                rx = nx;
                ry = ny;
                done = true;
                break;
            }

            rx = nx;
            ry = ny;
            nx = rx + dx[dir];
            ny = ry + dy[dir];
        }

        nx = bx + dx[dir];
        ny = by + dy[dir];

        while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (b[nx][ny] == 'O') return 0;
            if (b[nx][ny] == '#' || (nx == rx && ny == ry)) break;

            bx = nx;
            by = ny;
            nx = bx + dx[dir];
            ny = by + dy[dir];
        }

        if (done) return 2;
        else return 1;
    }

    return false;
}

int solve(int order) {
    rx = RX, ry = RY, bx = BX, by = BY;

    int cnt = 1;
    int dir = order % 4;
    bool horizontal = dir / 2;

    order /= 4;

    int move_res = move(dir);
    if (move_res == 2) return cnt;
    else if (move_res == 0) return MAX;

    for (cnt++; cnt <= 10; cnt++) {
        horizontal = !horizontal;
        dir = horizontal * 2 + order % 2;
        order /= 2;

        move_res = move(dir);
        if (move_res == 2) return cnt;
        else if (move_res == 0) break;
    }

    return MAX;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        for (int j = 0; j < m; j++) {
            if (b[i][j] == 'R') {
                b[i][j] = '.';
                RX = i;
                RY = j;
            } else if (b[i][j] == 'B') {
                b[i][j] = '.';
                BX = i;
                BY = j;
            } else if (b[i][j] == 'O') {
                OX = i;
                OY = j;
            }
        }
    }

    for (int i = 0; i < 2048; i++) {
        mn = min(mn, solve(i));
    }

    cout << (mn == MAX ? -1 : mn);
}
