#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k; cin >> n >> k;

    int ans = 1;

    for (int i = 1; i <= k; i++) {
        ans = ans * (n + 1 - i) / i;
    }

    cout << ans;
}
