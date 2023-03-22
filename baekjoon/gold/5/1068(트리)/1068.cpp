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

        for (int nxt : e[cur]) {
            if (nxt == par[cur] || vis[nxt]) continue;

            cnt++;
            vis[nxt] = true;
            q.push(nxt);
        }
        if (!cnt) leaf++;
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
        else {
            e[i].push_back(u);
            e[u].push_back(i);
        }
    }

    cin >> s;

    int ans = count_leaf(r) - count_leaf(s);

    if (s != r 
        && (par[s] == r && e[par[s]].size() == 1 || par[s] != r && e[par[s]].size() == 2)) ans++;
    
    cout << ans;
}
