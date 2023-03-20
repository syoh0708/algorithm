#include <bits/stdc++.h>

using namespace std;

int a[2005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, ans = 0; cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (i == j) continue;

            if (a[i] <= 0 && a[j] > 0) break;
            if (a[i] > 0 && j > i) break;

            int k = lower_bound(a + j + 1, a + n, a[i] - a[j]) - a;
            
            if (k == i) k++;
            if (k < n && a[i] == (a[j] + a[k])) {
                ans++;
                break;
            }
        }
    }

    cout << ans;
}
