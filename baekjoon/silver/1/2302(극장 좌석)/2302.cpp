#include <bits/stdc++.h>

using namespace std;

int n, m, pre, cur;
int d[41];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= n; i++) {
        d[i] = d[i - 1] + d[i - 2];
    }

    int ans = 1;

    while (m--) {
        cin >> cur;

        ans *= d[cur - pre - 1];
        pre = cur;
    }

    ans *= d[n - cur];

    cout << ans;
}
