#include <bits/stdc++.h>

using namespace std;

unordered_map<string, string> m2g;
unordered_map<string, pair<int, int>> g2m;
vector<string> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i = 0;
    

    cin >> n >> m;

    while (n--) {
        string group_name;
        int member_cnt;

        cin >> group_name >> member_cnt;

        pair<int, int> idx_range = {i, i + member_cnt};
        g2m[group_name] = idx_range;

        while (member_cnt--) {
            string name;

            cin >> name;

            m2g[name] = group_name;
            v.push_back(name);
        }

        sort(v.begin() + idx_range.first, v.begin() + idx_range.second);
        i = idx_range.second;
    }

    while (m--) {
        string query;
        int type;

        cin >> query >> type;

        if (type == 1) {
            cout << m2g[query] << '\n';
        } else {
            pair<int, int> p = g2m[query];

            for (int j = p.first; j < p.second; j++) {
                cout << v[j] << '\n';
            }
        }
    }
}
