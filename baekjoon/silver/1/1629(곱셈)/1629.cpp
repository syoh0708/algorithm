#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int mod(ll a, ll b, ll c) {
    if (b == 1) return a % c;

    ll val = mod(a, b / 2, c);
    ll ret = val * val % c;
    if (b % 2) ret = ret * a % c;

    return ret;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c, ans = 1LL;

    cin >> a >> b >> c;

    cout << mod(a, b, c);
}
