#include <bits/stdc++.h>

using namespace std;

int n, r, s;
int par[51];
vector<int> e[51];

int count_leaf(int k) {
    int leaf = 0;
    bool vis[51] = {};
    queue<int> q;

    q.push(k);
    vis[k] = true;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        int cnt = 0;

        if (!e[cur].size()) {
            leaf++;
            continue;
        }

        for (int nxt : e[cur]) {
            if (vis[nxt]) continue;

            cnt++;
            vis[nxt] = true;
            q.push(nxt);
        }
    }

    return leaf;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int u; cin >> u;

        par[i] = u;
        if (u == -1) r = i;
        else e[u].push_back(i);
    }

    cin >> s;

    if (r != s) e[par[s]].erase(lower_bound(e[par[s]].begin(), e[par[s]].end(), s));
    else e[s].clear();

    cout << (r == s ? 0 : count_leaf(r));
}
