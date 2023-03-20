#include <bits/stdc++.h>

using namespace std;

vector<int> e[10005];
int vals[10005];

int solve(int k) {
    int ans = 0;
    bool vis[10005] = {};
    queue<int> q;

    vis[k] = true;
    q.push(k);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int next : e[cur]) {
            if (vis[next]) continue;

            vis[next] = true;
            ans++;
            q.push(next);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, max_val = 0; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;

        e[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        int val = solve(i);

        max_val = max(max_val, val);
        vals[i] = val;
    }

    for (int i = 1; i <= n; i++) {
        if (vals[i] == max_val) cout << i << ' ';
    }
}
