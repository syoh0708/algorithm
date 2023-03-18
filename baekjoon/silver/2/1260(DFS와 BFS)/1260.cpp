#include <bits/stdc++.h>

using namespace std;

vector<int> e[1001];
vector<bool> vis_dfs(1001);
vector<bool> vis_bfs(1001);

void bfs(int v) {
    queue<int> q;
    vis_bfs[v] = true;
    q.push(v);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << ' ';

        for (int a : e[cur]) {
            if (vis_bfs[a]) continue;
            vis_bfs[a] = true;

            q.push(a);
        }
    }    
}

void dfs(int v) {
    stack<int> s;
    s.push(v);

    while (!s.empty()) {
        int cur = s.top(); s.pop();
        
        if (vis_dfs[cur]) continue;
        vis_dfs[cur] = true;
        cout << cur << ' ';

        int sz = e[cur].size();
        for (int i = sz - 1; i >= 0; i--) {
            if (vis_dfs[e[cur][i]]) continue;

            s.push(e[cur][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, v; cin >> n >> m >> v;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(e[i].begin(), e[i].end());
    }

    dfs(v);
    cout << '\n';
    bfs(v);
}
