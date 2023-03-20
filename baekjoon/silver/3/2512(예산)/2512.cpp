#include <bits/stdc++.h>

using namespace std;

int a[10005];
int n, p;

bool solve(int x) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += min(x, a[i]);
        if (sum > p) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> p;

    int st = 1, en = *max_element(a, a + n);

    while (st < en) {
        int mid = (st + en + 1) / 2;
        if (solve(mid)) st = mid;
        else en = mid - 1;
    }

    cout << st;
}
