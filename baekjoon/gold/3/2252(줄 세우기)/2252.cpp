#include <bits/stdc++.h>

using namespace std;

int n, m;
unordered_set<int> e1[32005];
unordered_set<int> e2[32005];
vector<bool> vis(32005);

void erase(int k) {
    vis[k] = true;
    cout << k << ' ';

    for (int nxt : e1[k]) {
        e2[nxt].erase(k);

        if (!e2[nxt].size()) erase(nxt);
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while (m--) {
        int u, v; cin >> u >> v;
        
        e1[u].insert(v);
        e2[v].insert(u);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        if (e2[i].size() > 0) continue;

        erase(i);
    }
}
