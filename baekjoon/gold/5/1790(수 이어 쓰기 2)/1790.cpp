#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, k; cin >> n >> k;

    ll digit = 1, cnt = 9, num = 1;

    while (k - digit * cnt > 0) {
        k -= digit * cnt;
        digit++;
        cnt *= 10;
        num *= 10;
    }

    num += (k - 1) / digit;
    string n_str = to_string(num);

    if (n < num) cout << -1;
    else cout << n_str[(k - 1) % digit];
}
