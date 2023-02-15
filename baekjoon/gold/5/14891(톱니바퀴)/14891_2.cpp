#include <bits/stdc++.h>

using namespace std;

string a[4];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c, r;

    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }

    cin >> n;

    while (n--) {
        cin >> c >> r;
        c--;

        int dir[4] = {};
        dir[c] = r;

        int right = c, left = c;

        for (int i = 0; i < 3; i++) {
            right++; left--;
            if (right < 4 && a[right - 1][2] != a[right][6]) {
                dir[right] = -dir[right - 1];
            }
            if (left >= 0 && a[left][2] != a[left + 1][6]) {
                dir[left] = -dir[left + 1];
            }
        }

        for (int i = 0; i < 4; i++) {
            cout << dir[i] << ' ';
        }
        cout << '\n';

        for (int i = 0; i < 4; i++) {
            if (dir[i] == 1) {
                rotate(a[i].begin(), a[i].begin() + 7, a[i].end());
            } else if (dir[i] == -1) {
                rotate(a[i].begin(), a[i].begin() + 1, a[i].end());
            }
        }
    }

    int ans = 0;


    cout << '\n';
    for (int i = 0; i < 4; i++) {
        cout << a[i] << '\n';
    }

    for (int i = 0; i < 4; i++) {
        ans += (a[i][0] - '0') << i;
    }

    cout << ans;
}
