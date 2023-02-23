#include <bits/stdc++.h>

using namespace std;

long long d[100] = {1, 1, 1, 2, 2};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n; cin >> t;

    for (int i = 5; i < 100; i++) {
        d[i] = d[i - 1] + d[i - 5];
    }
    
    while (t--) {
        cin >> n;

        cout << d[n - 1] << '\n';
    }
}
