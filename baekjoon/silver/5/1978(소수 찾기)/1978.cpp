#include <bits/stdc++.h>

using namespace std;

int is_prime(int x) {
    if (x == 1) return 0;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }

    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, ans = 0; cin >> n;

    while (n--) {
        int x; cin >> x;

        ans += is_prime(x);
    }

    cout << ans;
}
