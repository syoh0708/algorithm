#include <bits/stdc++.h>

using namespace std;

int a[50];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int ans = 0;
    
    int neg_idx = upper_bound(a, a + n, 0) - a;

    int i = 0;
    while (i + 1 < neg_idx) {
        ans += (a[i] * a[i + 1]);
        i += 2;
    }
    if (i == neg_idx - 1) ans += a[i];
    
    int j = n - 1;
    while (j - 1 >= neg_idx) {
        ans += (a[j] * a[j - 1]);
        if (a[j - 1] == 1) ans++;
        j -= 2;
    }
    if (j == neg_idx) ans += a[j];

    cout << ans;
}
