#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, m, ans = 0; cin >> n >> m;

    priority_queue<ll, vector<ll>, greater<ll>> q;

    for (int i = 0; i < n; i++) {
        ll x; cin >> x;

        q.push(x);
    }

    while (m--) {
        ll x = q.top(); q.pop();
        ll y = q.top(); q.pop();

        q.push(x + y);
        q.push(x + y);
    }

    while (!q.empty()) {
        ans += q.top(); q.pop();
    }

    cout << ans;
}
