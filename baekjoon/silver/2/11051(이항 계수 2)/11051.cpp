#include <bits/stdc++.h>

using namespace std;

int comb[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k; cin >> n >> k;

    comb[1][0] = 1;
    comb[1][1] = 1;

    k = min(k, n - k);

    for (int i = 2; i <= n; i++) {
        comb[i][0] = 1;

        for (int j = 1; j <= k; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % 10007;
        }
    }

    cout << comb[n][k];
}
