#include <bits/stdc++.h>

using namespace std;

int n, diam;
vector<pair<int, int>> e[10005];

pair<int, int> dfs(int cur) {
    int x = 0, y = 0;
    vector<int> dist;

    for (auto nxt : e[cur]) {
        pair<int, int> d = dfs(nxt.first);
        dist.push_back(d.first + nxt.second);
    }

    sort(dist.begin(), dist.end(), greater<int>());
    if (dist.size() > 0) x = dist[0];
    if (dist.size() > 1) y = dist[1];
    diam = max(diam, x + y);

    return {x, y};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v, d; cin >> u >> v >> d;
        
        e[u].push_back({v, d});
    }

    dfs(1);

    cout << diam;
}
