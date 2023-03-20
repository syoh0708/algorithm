#include <bits/stdc++.h>

using namespace std;

vector<int> e[101];

int solve(int p) {
    int ans = 0, vis[101] = {};
    queue<pair<int, int>> q;

    vis[p] = true;
    q.push({p, 0});

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        ans += cur.second;

        for (auto next : e[cur.first]) {
            if (vis[next]) continue;

            vis[next] = true;
            q.push({next, cur.second + 1});
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, min_val = 1'000'000'000, ans; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        int val = solve(i);

        if (val < min_val) {
            min_val = val;
            ans = i;
        }
    }

    cout << ans;
}
