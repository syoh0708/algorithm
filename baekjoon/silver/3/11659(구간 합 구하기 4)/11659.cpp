#include <bits/stdc++.h>

using namespace std;

int sum[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int a;

        cin >> a;

        sum[i] = sum[i - 1] + a;    
    }

    while (m--) {
        int i, j;

        cin >> i >> j;

        cout << sum[j] - sum[i - 1] << '\n';
    }
}
