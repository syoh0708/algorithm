#include <bits/stdc++.h>

using namespace std;

int r, c, m, ans;
tuple<int, int, int> b[105][105]; // s, d, z
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void move() {
    tuple<int, int, int> tmp[105][105] = {};

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int s, d, z;

            tie(s, d, z) = b[i][j];

            if (!z) continue;

            bool horizontal = d / 2;
            int positive = d % 2;
            int sign = positive ? 1 : -1;
            int ni = i, nj = j, ns = s, nd, nz = z, cs, cd, cz;

            if (horizontal) {
                nj += s * sign;
                while (nj < 0 || nj >= c) {
                    if (nj < 0) {
                        nj = -nj;
                        positive = !positive;
                    } else if (nj >= c) {
                        nj = 2 * c - 2 - nj;
                        positive = !positive;
                    }
                }
            } else {
                ni += s * sign;
                while (ni < 0 || ni >= r) {
                    if (ni < 0) {
                        ni = -ni;
                        positive = !positive;
                    } else if (ni >= r) {
                        ni = 2 * r - 2 - ni;
                        positive = !positive;
                    }
                }
            }

            nd = horizontal * 2 + positive;

            tie(cs, cd, cz) = tmp[ni][nj];
            
            if (nz > cz) {
                tmp[ni][nj] = {ns, nd, nz};
            }
        }
    }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            b[i][j] = tmp[i][j];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> m;

    while (m--) {
        int i, j, s, d, z;

        cin >> i >> j >> s >> d >> z;

        if (d > 2) d = 7 - d;
        s %= (2 * ((d - 1) / 2 ? c : r) - 2);

        b[i - 1][j - 1] = {s, d - 1, z};
    }

    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            int s, d, z;

            tie(s, d, z) = b[i][j];

            if (z) {
                ans += z;
                b[i][j] = {0, 0, 0};
                break;
            }
        }

        move();
    }

    cout << ans;
}
