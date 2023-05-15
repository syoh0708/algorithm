#include <bits/stdc++.h>

using namespace std;

int n, s, e, k1, k2;
int a[505];

void shift(int k) {
    int tmp[505] = {};

    for (int i = 0; i < n; i++) tmp[(i + k) % n] = a[i];
    for (int i = 0; i < n; i++) a[i] = tmp[i];
}

bool valid(int idx) {
    return (a[idx] + 1) % n == a[(idx + 1) % n] % n || (a[(idx + n - 1) % n] + 1) % n == a[idx] % n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;

        a[i] = x - 1;
    }

    bool all_invalid = true;
    for (int i = 0; i < n; i++) {
        if (valid(i)) {
            all_invalid = false;
            break;
        }
    }

    if (all_invalid) {
        s = 0;
        e = n - 1;
    } else {
        while (!valid(s)) s = (s + 1) % n;
        while (valid(s)) s = (s + 1) % n;
        e = s;
        while (!valid(e)) e = (e + 1) % n;
        e = (e + n - 1) % n;
    }

    if (!all_invalid && (e < s || e > n - 3)) k2 = n - s;
    else k2 = 1;
    shift(k2);

    if (!all_invalid) {
        s = (s + k2) % n;
        e = (e + k2) % n;
    }

    k1 = (a[e] - s + n) % n;
    if (k1 == 0) {
        int add = 0;
        if (k2 + 1 == n) {
            add = 2;
            k2 = 1;
        } else {
            add = 1;
            k2++;
        }
        shift(add);
        if (!all_invalid) {
            s = (s + add) % n;
            e = (e + add) % n;
        }
        k1 = (a[e] - s + n) % n;
    }

    cout << k1 << '\n';
    cout << s + 1 << ' ' << e + 1 << '\n';
    cout << k2 << '\n';
}
