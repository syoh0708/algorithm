#include <bits/stdc++.h>

using namespace std;

vector<int> e[20005];
int n, m, max_dist, cnt, ans, dist[20005];
bool vis[20005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    queue<pair<int, int>> q;

    q.push({1, 0});
    vis[1] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        dist[cur.first] = cur.second;
        max_dist = max(max_dist, cur.second);

        for (auto next : e[cur.first]) {
            if (vis[next]) continue;

            vis[next] = true;
            q.push({next, cur.second + 1});
        }
    }

    for (int i = n; i > 0; i--) {
        if (dist[i] == max_dist) {
            cnt++;
            ans = i;
        }
    }

    cout << ans << ' ' << max_dist << ' ' << cnt;
}
