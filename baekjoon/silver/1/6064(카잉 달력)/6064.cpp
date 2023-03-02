#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) {
        int m, n, x, y, ans = -2;

        cin >> m >> n >> x >> y;

        x--; y--;

        int l = lcm(m, n);

        for (int i = x; i < l; i += m) {
            if (i % n == y) ans = i;
        }
        

        cout << ans + 1 << '\n';
    }
}
