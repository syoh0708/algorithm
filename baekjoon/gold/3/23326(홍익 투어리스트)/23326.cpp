#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q, pos = 1;
    set<int> p;

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        bool b; cin >> b;

        if (b) p.insert(i);
    }

    while (q--) {
        int op; cin >> op;

        if (op == 1) {
            int x; cin >> x;

            if (p.find(x) != p.end()) {
                p.erase(x);
            } else {
                p.insert(x);
            }
        } else if (op == 2) {
            int x; cin >> x;

            x %= n;
            pos += x;
            if (pos > n) pos -= n;
        } else { // op == 3
            auto it = p.lower_bound(pos);
            if (it != p.end()) {
                cout << *it - pos << '\n';
            } else {
                if (p.empty()) {
                    cout << -1 << '\n';
                } else {
                    cout << n - (pos - *p.begin()) << '\n';
                }
            }
        }
    }
}
