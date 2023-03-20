#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k; cin >> k;

    while (k--) {
        int n, m; cin >> n >> m;

        bool is_bigraph = true;
        vector<vector<int>> e(n + 1);
        vector<int> team(n + 1);

        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;

            e[u].push_back(v);
            e[v].push_back(u);
        }

        for (int i = 1; i <= n; i++) {
            if (team[i]) continue;

            queue<int> q;
            team[i] = 1;
            q.push(i);

            while (!q.empty()) {
                int cur = q.front(); q.pop();

                for (int next : e[cur]) {
                    if (team[next]) {
                        if (team[cur] + team[next] == 3) continue;
                        else {
                            is_bigraph = false;
                            break;
                        }
                    }

                    team[next] = 3 - team[cur];
                    q.push(next);
                }

                if (!is_bigraph) break;
            }

            if (!is_bigraph) break;
        }

        cout << (is_bigraph ? "YES" : "NO") << '\n';
    }
}
