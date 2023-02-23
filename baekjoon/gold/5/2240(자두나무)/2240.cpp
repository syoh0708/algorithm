#include <bits/stdc++.h>

using namespace std;

int d[1001][31];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, w, a; cin >> t >> w;

    for (int i = 1; i <= t; i++) {
        cin >> a;

        d[i][0] = d[i - 1][0];
        if (a == 1) d[i][0]++; 

        for (int j = 1; j <= w; j++) {
            d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]);
            if ((j + a) % 2) d[i][j]++;
        }
    }

    cout << *max_element(d[t], d[t] + w + 1);
}
