#include <bits/stdc++.h>

using namespace std;

int n, max_len;
int a[1'000'005];
int b[1'000'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        b[a[i]] = b[a[i] - 1] + 1;
        max_len = max(max_len, b[a[i]]);
    }


    cout << n - max_len;
}
