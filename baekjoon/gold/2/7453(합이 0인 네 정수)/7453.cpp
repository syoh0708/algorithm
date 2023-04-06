#include <bits/stdc++.h>

using namespace std;

int n;
long long ans;
int a[4005], b[4005], c[4005], d[4005];
int sum[16000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    int nn = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum[nn++] = a[i] + b[j];
        }
    }

    sort(sum, sum + nn);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val = -(c[i] + d[j]);
            ans += (upper_bound(sum, sum + nn, val) - lower_bound(sum, sum + nn, val));
        }
    }

    cout << ans;
}
