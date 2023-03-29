#include <bits/stdc++.h>

using namespace std;

int n, m, ans, v_cnt;
vector<pair<int, int>> e[10005];
bool vis[10005];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while (m--) {
        int u, v, cost; cin >> u >> v >> cost;

        e[u].push_back({v, cost});
        e[v].push_back({u, cost});
    }

    vis[1] = true;
    v_cnt++;
    for (auto cur : e[1]) q.push({cur.second, 1, cur.first});

    while (v_cnt < n) {
        int cost, u, v;
        
        do  {
            tie(cost, u, v) = q.top(); q.pop();
        } while (vis[v]);

        vis[v] = true;
        v_cnt++;
        ans += cost;

        for (auto nxt : e[v]) {
            if (vis[nxt.first]) continue;

            q.push({nxt.second, v, nxt.first});
        }
    }

    cout << ans;
}
