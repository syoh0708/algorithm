#include <bits/stdc++.h>

using namespace std;

pair<int, int> a[200000];
multiset<int> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        auto it = m.lower_bound(-1 * a[i].first);
        if (it != m.end()) {
            m.erase(it);
        }

        m.insert(-1 * a[i].second);
    }

    cout << m.size();
}
