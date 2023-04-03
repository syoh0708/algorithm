#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000'000;
int n, m;
int dist[1005];
vector<pair<int, int>> e[1005];
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while (m--) {
        int u, v, w; cin >> u >> v >> w;

        e[u].push_back({w, v});
    }

    int src, dest; cin >> src >> dest;

    pq.push({0, src});
    fill(dist + 1, dist + n + 1, MAX);
    dist[src] = 0;

    while (!pq.empty()) {
        pair<int, int> cur = pq.top(); pq.pop();

        if (cur.first != dist[cur.second]) continue;

        for (auto nxt : e[cur.second]) {
            if (dist[cur.second] + nxt.first < dist[nxt.second]) {
                dist[nxt.second] = dist[cur.second] + nxt.first;
                pq.push({dist[nxt.second], nxt.second});
            }
        }
    }

    cout << dist[dest];
}
