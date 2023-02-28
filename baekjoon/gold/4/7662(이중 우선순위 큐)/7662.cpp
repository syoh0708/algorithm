#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, k; cin >> t;

    while (t--) {
        cin >> k;

        multiset<int> s;

        while (k--) {
            char op; 
            int val;

            cin >> op >> val;

            if (op == 'I') {
                s.insert(val);
            } else {
                if (s.empty()) continue;

                if (val == 1) s.erase(prev(s.end()));
                else s.erase(s.begin());
            }
        }

        if (s.empty()) cout << "EMPTY\n";
        else cout << *s.rbegin() << ' ' << *s.begin() << '\n';
    }
}
