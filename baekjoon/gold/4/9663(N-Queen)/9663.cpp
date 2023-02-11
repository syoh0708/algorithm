#include <bits/stdc++.h>

using namespace std;

int n, ans;
bool x[15], y[15], sum[29], sub[29];

void func(int c) {
    if (c == n) {
        ans++;
        return;
    }

    int i = c;

    for (int j = 0; j < n; j++) {
        if (y[j]) continue;

        if (!sum[i + j] && !sub[i - j + 14]) {
            x[i] = true;
            y[j] = true;
            sum[i + j] = true;
            sub[i - j + 14] = true;
            func(c + 1);
            x[i] = false;
            y[j] = false;
            sum[i + j] = false;
            sub[i - j + 14] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    func(0);

    cout << ans;
}
