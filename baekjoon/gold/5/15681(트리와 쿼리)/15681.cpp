#include <bits/stdc++.h>

using namespace std;

int n, r, q;
vector<int> e[100005];
int sub[100005];
bool vis[100005];

int solve(int cur) {
    int ans = 1;
    vis[cur] = true;

    for (int nxt : e[cur]) {
        if (vis[nxt]) continue;
        ans += solve(nxt);
    }
    sub[cur] = ans;
    
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> q;

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        
        e[u].push_back(v);
        e[v].push_back(u);
    }

    solve(r);

    while (q--) {
        int query; cin >> query;

        cout << sub[query] << '\n';
    }
}
