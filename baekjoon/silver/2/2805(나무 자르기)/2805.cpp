#include <bits/stdc++.h>

using namespace std;

int n, m;
int tree[1'000'005];

bool solve(int k) {
    long long meter = 0;

    for (int i = 0; i < n; i++) {
        meter += max(0, tree[i] - k);
        if (meter >= m) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }

    int st = 0, en = 1'000'000'000;

    while (st < en) {
        int mid = (st + en + 1) / 2;

        if (solve(mid)) st = mid;
        else en = mid - 1;
    }

    cout << st;
}
