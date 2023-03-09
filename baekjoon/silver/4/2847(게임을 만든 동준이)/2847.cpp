#include <bits/stdc++.h>

using namespace std;

int a[105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;

    for (int i = n - 1; i >= 0; i--) {
        cin >> a[i];
    }

    int ans = 0, max_score = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < max_score) {
            max_score = a[i];
        } else {
            max_score--;
            ans += (a[i] - max_score);
        }
    }

    cout << ans;
}
