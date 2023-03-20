#include <bits/stdc++.h>

using namespace std;

int a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    int min_sum = 2'000'000'001, ii, jj;

    for (int i = 0; i < n; i++) {
        int j = lower_bound(a + i + 1, a + n, -a[i]) - a;
        if (j < n && abs(a[i] + a[j]) < min_sum) {
            ii = i;
            jj = j;
            min_sum = abs(a[i] + a[j]);
        }
        if (j - 1 > i && abs(a[i] + a[j - 1]) < min_sum) {
            ii = i;
            jj = j - 1;
            min_sum = abs(a[i] + a[j - 1]);
        }

        if (min_sum == 0) break;
    }

    cout << a[ii] << ' ' << a[jj];
}
