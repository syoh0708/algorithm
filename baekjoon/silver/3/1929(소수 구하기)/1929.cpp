#include <bits/stdc++.h>

using namespace std;

bool is_composite[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> m >> n;

    is_composite[1] = true;

    for (int i = 2; i * i <= n; i++) {
        if (is_composite[i]) continue;

        for (int j = 2; j * i <= n; j++) {
            is_composite[i * j] = true;
        }
    }

    for (int i = m; i <= n; i++) {
        if (!is_composite[i]) cout << i << '\n';
    }
}
