#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 0;

    while (1) {
        tc++;
        int n, m, cnt = 0; cin >> n >> m;

        if (n == 0 && m == 0) break;

        vector<int> e[501];
        int par[501] = {};
        bool vis[501] = {};
        queue<int> q;
        

        while (m--) {
            int u, v; cin >> u >> v;

            e[u].push_back(v);            
            e[v].push_back(u);            
        }

        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            bool is_tree = true;

            vis[i] = true;
            q.push(i);

            while (!q.empty()) {
                int cur = q.front(); q.pop();

                for (int next : e[cur]) {
                    if (vis[next]) {
                        if (par[cur] != 0 && par[cur] != next) is_tree = false;
                        
                        continue;
                    }

                    vis[next] = true;
                    par[next] = cur;
                    q.push(next);
                }
            }

            if (is_tree) cnt++;
        }

        cout << "Case " << tc << ": ";
        if (cnt == 0) cout << "No trees.\n";
        else if (cnt == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << cnt << " trees.\n";
    }
}
