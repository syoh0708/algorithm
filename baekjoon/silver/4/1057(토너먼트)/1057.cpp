#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, a, b, ans = 1; cin >> n >> a >> b;

    a--;
    b--;

    if (a > b) swap(a, b);

    while (1) {
        if (b % 2 && b == a + 1) break;

        a /= 2;
        b /= 2;
        ans++;
    }

    cout << ans;
}
