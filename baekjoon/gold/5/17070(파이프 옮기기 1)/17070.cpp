#include <bits/stdc++.h>

using namespace std;

bool wall[17][17];
int h[17][17], v[17][17], d[17][17];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> wall[i][j];
        }
    }

    h[1][2] = 1;

    for (int sum = 4; sum <= 2 * n ; sum++) {
        for (int i = 1; i <= n; i++) {
            int j = sum - i;

            if (wall[i][j]) continue;

            h[i][j] = h[i][j - 1] + d[i][j - 1];
            v[i][j] = v[i - 1][j] + d[i - 1][j];

            if (wall[i - 1][j] || wall[i][j - 1]) continue;

            d[i][j] = h[i - 1][j - 1] + v[i - 1][j - 1] + d[i - 1][j - 1];
        }
    }

    cout << h[n][n] + v[n][n] + d[n][n];
}
