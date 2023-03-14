#include <bits/stdc++.h>

using namespace std;

int a[10000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int i = 0, j = 0, cur = 0, ans = 0;

    while (1) {
        if (cur < m) {
            if (j == n) break;
            cur += a[j++];
        } else {
            cur -= a[i++];
        }

        if (cur == m) ans++;
    }

    cout << ans;
}
