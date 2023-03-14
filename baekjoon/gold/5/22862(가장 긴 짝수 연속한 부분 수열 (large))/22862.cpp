#include <bits/stdc++.h>

using namespace std;

int a[1'000'000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k; cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int i = 0, j = 0, removed = 0, ans = 0;

    while (i < n) {
        if (a[i++] % 2) {
            if (removed < k) {
                removed++;
            } else {
                while (a[j] % 2 == 0) j++;
                j++;
            }
        } else {
            ans = max(i - j - removed, ans);
        }
    }

    cout << ans;
}
