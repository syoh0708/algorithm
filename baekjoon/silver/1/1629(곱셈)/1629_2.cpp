#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(ll a, ll b, ll c) {
    if (!b) return 1;

    ll tmp = solve(a, b / 2, c);

    tmp = tmp * tmp % c;

    if (b % 2) tmp = tmp * a % c;

    return tmp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c; cin >> a >> b >> c;

    cout << solve(a, b, c);
}
