#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[10005];
ll k, n, mn = 0, mx = 0;

ll cnt(ll len) {
    ll ans = 0;

    for (int i = 0; i < k; i++) ans += (a[i] / len);

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k >> n;

    for (int i = 0; i < k; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    if (cnt(mx) >= n) {
        cout << mx;
        return 0;
    }

    while (mx - mn > 1) {
        ll mid = (mx + mn) / 2;

        if (cnt(mid) < n) mx = mid;
        else mn = mid;
    }

    cout << mn;
}
