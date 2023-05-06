#include <bits/stdc++.h>

using namespace std;

int n;
int a[200'020];
int b[400'020];

vector<int> failure(int x[]) {
    vector<int> f(n);

    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0 && x[i] != x[j]) j = f[j - 1];
        if (x[i] == x[j]) f[i] = ++j;
    }

    return f;
}

bool kmp(int x[], int y[]) {
    vector<int> f = failure(y);
    int j = 0;
    for (int i = 0; i < 2 * n; i++) {
        while (j > 0 && x[i] != y[j]) j = f[j - 1];
        if (x[i] == y[j]) j++;
        if (j == n) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);
    
    int a0 = a[0] + 360'000 - a[n - 1];
    int b0 = b[0] + 360'000 - b[n - 1];

    for (int i = n - 1; i > 0; i--) {
        a[i] = a[i] - a[i - 1];
        b[i] = b[i] - b[i - 1];
    }

    a[0] = a0;
    b[0] = b0;

    for (int i = n; i < 2 * n; i++) b[i] = b[i - n];

    cout << (kmp(b, a) ? "possible" : "impossible");
}
