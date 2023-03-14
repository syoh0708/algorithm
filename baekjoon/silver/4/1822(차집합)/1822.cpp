#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    set<int> s;
    int n, m; cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        s.insert(a);
    }

    for (int j = 0; j < m; j++) {
        int a; cin >> a;
        s.erase(a);
    }

    cout << s.size() << '\n';
    for (int a : s) cout << a << ' ';
}
