#include <bits/stdc++.h>

using namespace std;

int a[1'000'005];
int m, n;

bool can_give(int k) {
    long long cnt = 0;

    for (int i = 0; i < n; i++) {
        cnt += a[i] / k;
        if (cnt >= m) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int st = 0, en = 1'000'000'000;

    while (st < en) {
        int mid = (st + en + 1) / 2;

        if (can_give(mid)) st = mid;
        else en = mid - 1;
    }

    cout << st;
}
