#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> e[1005];
int deg[1005];
queue<int> q;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while (m--) {
        int no, u, v; cin >> no >> u;

        for (int i = 1; i < no; i++) {
            cin >> v;

            e[u].push_back(v);
            u = v;
            deg[v]++;
        }
    }

    for (int i = 1; i <= n; i++) 
        if (!deg[i]) q.push(i);
    
    while (!q.empty()) {
        int cur = q.front(); q.pop();

        v.push_back(cur);

        for (int nxt : e[cur]) {
            deg[nxt]--;
            if (!deg[nxt]) q.push(nxt);
        }
    }

    if (v.size() < n) cout << 0;
    else {
        for (int k : v) cout << k << ' ';
    }
}
