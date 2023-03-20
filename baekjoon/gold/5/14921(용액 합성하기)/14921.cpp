#include <bits/stdc++.h>

using namespace std;

int a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, ans = 2'000'000'002; cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n - 1; i++) {
        int j = lower_bound(a + i + 1, a + n, -a[i]) - a;

        if (j < n && abs(a[i] + a[j]) < abs(ans)) ans = a[i] + a[j];
        if (j - 1 > i && abs(a[i] + a[j - 1]) < abs(ans)) ans = a[i] + a[j - 1];

        if (!ans) break;
    }

    cout << ans;
}
