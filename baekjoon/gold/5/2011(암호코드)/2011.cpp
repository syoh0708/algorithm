#include <bits/stdc++.h>

using namespace std;

int n;
int d[5005][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string pw; cin >> pw;

    n = pw.size();

    d[0][0] = 1;
    d[1][0] = (pw[0] != '0');

    for (int i = 2; i <= n; i++) {
        d[i][0] = (pw[i - 1] != '0' ? (d[i - 1][0] + d[i - 1][1]) % 1000000 : 0);
        d[i][1] = (pw[i - 2] != '0' && ((pw[i - 2] - '0') * 10 + (pw[i - 1] - '0') < 27 ) ? (d[i - 2][0] + d[i - 2][1]) % 1000000 : 0);
    }

    cout << (d[n][0] + d[n][1]) % 1000000;
}
