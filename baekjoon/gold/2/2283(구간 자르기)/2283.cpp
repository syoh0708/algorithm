#include <bits/stdc++.h>

using namespace std;

int n, k, mn = 1'000'000, mx;;
int sum[1'000'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;

        v.push_back({x, 1});
        v.push_back({y, -1});
        if (x < mn) mn = x;
        if (y > mx) mx = y;
    }

    sort(v.begin(), v.end());

    int val = 0, ptr = 0;

    for (int i = mn + 1; i <= mx; i++) {
        while (v[ptr].first == i - 1) {
            val += v[ptr].second;
            ptr++;
        }

        sum[i] = val + sum[i - 1];
    }

    int i = 0, j = 0;

    while (j <= mx) {
        int cur = sum[j] - sum[i];

        if (cur < k) j++;
        else if (cur > k) i++;
        else {
            cout << i << ' ' << j;
            return 0;
        }
    }

    cout << "0 0";
}
