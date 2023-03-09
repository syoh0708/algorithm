#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[1000000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        for (int i = n - 1; i >= 0; i--) {
            cin >> a[i];
        }

        int max_price = a[0];
        ll ans = 0;

        for (int i = 1; i < n; i++) {
            if (a[i] < max_price) ans += (max_price - a[i]);
            else max_price = a[i];
        }

        cout << ans << '\n';
    }
}
