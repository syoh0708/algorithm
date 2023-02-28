#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long ans = 0;
    int n, k; cin >> n >> k;
    vector<pair<int, int>> jw;
    multiset<int> bag;

    for (int i = 0; i < n; i++) {
        int m, v;

        cin >> m >> v;

        jw.push_back({v, m});
    }

    for (int i = 0; i < k; i++) {
        int c; cin >> c;

        bag.insert(c);
    }

    sort(jw.begin(), jw.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.first != b.first) return a.first > b.first;

        return a.second < b.second;
    });

    for (auto cur_jw : jw) {
        auto cur_bag = bag.lower_bound(cur_jw.second);
        if (cur_bag != bag.end()) {
            bag.erase(cur_bag);
            ans += cur_jw.first;
        }

        if (bag.empty()) break;
    }

    cout << ans;
}
