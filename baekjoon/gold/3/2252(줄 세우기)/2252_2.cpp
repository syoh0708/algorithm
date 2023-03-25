#include <bits/stdc++.h>

using namespace std;

int n, m;
int indg[32005];
vector<int> e[32005];
queue<int> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while (m--) {
        int u, v; cin >> u >> v;
        
        e[u].push_back(v);
        indg[v]++;
    }

    for (int i = 1; i <= n; i++) 
        if (!indg[i]) q.push(i);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        cout << cur << ' ';

        for (int nxt : e[cur]) {
            indg[nxt]--;

            if (!indg[nxt]) q.push(nxt);
        }
    }
}
