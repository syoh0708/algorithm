#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000'000;
int n, k;
int a[105];
int d[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> a[i];

    fill(d + 1, d + k + 1, MAX);

    for (int i = 1; i <= k; i++)
        for (int j = 0; j < n; j++)
            if (i - a[j] >= 0) d[i] = min(d[i], d[i - a[j]] + 1);

    cout << (d[k] == MAX ? -1 : d[k]); 
}
