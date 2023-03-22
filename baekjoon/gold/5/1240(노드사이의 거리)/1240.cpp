#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int>> e[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n - 1; i++) {
        int u, v, d; cin >> u >> v >> d;
        
        e[u].push_back({v, d});
        e[v].push_back({u, d});
    }

    while (m--) {
        int u, v; cin >> u >> v;
        int dist[1005] = {};
        bool vis[1005] = {};

        queue<pair<int, int>> q;

        q.push({u, 0});
        
        while (!q.empty()) {
            auto [cur, d] = q.front(); q.pop();

            if (cur == v) {
                cout << d << '\n';
                break;
            }

            for (auto [nxt, nxtd] : e[cur]) {
                if (vis[nxt]) continue;

                vis[nxt] = true;
                q.push({nxt, d + nxtd});
            }
        }
    }
}
