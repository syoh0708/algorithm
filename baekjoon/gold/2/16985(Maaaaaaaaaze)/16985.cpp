#include <bits/stdc++.h>

using namespace std;

bool cube[5][4][5][5]; // floor, rotate, row, column
int plate[5] = {0, 1, 2, 3, 4};
int rotation = 0;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

bool get_cube_val(int f, int r, int c) {
    int tmp = rotation;
    int real_floor = plate[f];

    while (f > 0) {
        tmp /= 4;
        f--;
    }
    
    return cube[real_floor][tmp % 4][r][c];
}

int dist() {
    int d[5][5][5];
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            fill(d[i][j], d[i][j] + 5, -1);
        }
    }

    if (!get_cube_val(0, 0, 0)) return 10000;

    queue<tuple<int, int, int>> q;

    q.push({0, 0, 0});
    d[0][0][0] = 0;

    while (!q.empty()) {
        int f, r, c;
        tie(f, r, c) = q.front(); q.pop();

        for (int dir = 0; dir < 6; dir++) {
            int nf = f + dx[dir];
            int nr = r + dy[dir];
            int nc = c + dz[dir];

            if (nf < 0 || nf > 4 || nr < 0 || nr > 4 || nc < 0 || nc > 4) continue;
            if (!get_cube_val(nf, nr, nc) || d[nf][nr][nc] >= 0) continue;

            q.push({nf, nr, nc});
            d[nf][nr][nc] = d[f][r][c] + 1;

            if (nf == 4 && nr == 4 && nc == 4) return d[nf][nr][nc];
        }
    }

    return 10000;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 10000;
    
    for (int i = 0; i < 5; i++) { // floor
        for (int j = 0; j < 5; j++) { // row
            for (int k = 0; k < 5; k++) { // column
                bool a; cin >> a;

                if (a) {
                    cube[i][0][j][k] = a;
                    cube[i][1][k][4 - j] = a;
                    cube[i][2][4 - j][4 - k] = a;
                    cube[i][3][4 - k][j] = a;
                }
            }
        }
    }

    do {
        for (int i = 0; i < 1024; i++) {
            rotation = i;
            ans = min(ans, dist());
            if (ans == 12) break;
        }
    } while (next_permutation(plate, plate + 5));

    cout << (ans == 10000 ? -1 : ans);
}
