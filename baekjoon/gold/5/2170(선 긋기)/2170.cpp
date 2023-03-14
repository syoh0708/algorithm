#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

pair<int, int> a[1'000'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n);

    int st = a[0].first, en = a[0].second;

    for (int i = 1; i < n; i++) {
        if (a[i].first < en) en = max(en, a[i].second);
        else {
            ans += (en - st);
            st = a[i].first;
            en = a[i].second;
        }
    }

    ans += (en - st);

    cout << ans;
}
