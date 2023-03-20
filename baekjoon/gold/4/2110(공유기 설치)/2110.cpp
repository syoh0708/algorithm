#include <bits/stdc++.h>

using namespace std;

int a[200'005];
int n, c;

bool solve(int l) {
    int pos = 0, cnt = 1;

    while (cnt++ < c) {
        pos = lower_bound(a + pos + 1, a + n, a[pos] + l) - a;
        if (pos == n) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> c;

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    int st = 1, end = 1'000'000'000;

    while (st < end) {
        int mid = (st + end + 1) / 2;

        if (solve(mid)) st = mid;
        else end = mid - 1;
    }

    cout << st;
}
