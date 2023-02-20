#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;

    cin >> t;

    while (t--) {
        int ans = 1;
        unordered_map<string, int> m;

        cin >> n;

        while (n--) {
            string name, type;

            cin >> name >> type;

            m[type]++;
        }

        for (auto p : m) {
            ans *= p.second + 1;
        }

        cout << ans - 1 << '\n';
    }
}
