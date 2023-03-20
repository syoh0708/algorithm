#include <bits/stdc++.h>

using namespace std;

int a[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    long long ans = 0;

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    for (int i = 0; i < n - 2; i++) {
        if (a[i] > 0) break;

        for (int j = i + 1; j < n - 1; j++) {
            if (a[i] + a[j] > 0) break;

            int target = -(a[i] + a[j]);

            ans += upper_bound(a + j + 1, a + n, target) - lower_bound(a + j + 1, a + n, target);
        }
    }

    cout << ans;
}
