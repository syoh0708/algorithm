#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, l;

    cin >> k >> l;

    unordered_map<string, int> m;
    vector<pair<int, string>> v;

    for (int i = 0; i < l; i++) {        
        string s;

        cin >> s;

        m[s] = i;
    }
    
    for (auto p : m) {
        v.push_back({p.second, p.first});
    }
    sort(v.begin(), v.end());

    k = min(k, (int) v.size());

    for (int i = 0; i < k; i++) {
        cout << v[i].second << '\n';
    }
}
