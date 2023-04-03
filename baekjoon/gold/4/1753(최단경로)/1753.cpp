#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000'000;
int n, m, st;
int dist[20005];
bool vis[20005];
vector<pair<int, int>> e[20005];
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> st;

    while (m--) {
        int u, v, w; cin >> u >> v >> w;

        e[u].push_back({w, v});
    }

    
    int cur = st, cnt = 1;
    fill(dist + 1, dist + n + 1, MAX);
    dist[st] = 0;
    vis[st] = true;
    while (cnt < n) {
        for (auto nxt : e[cur]) {
            if (dist[cur] + nxt.first < dist[nxt.second]) {
                dist[nxt.second] = dist[cur] + nxt.first;
                q.push({dist[cur] + nxt.first, nxt.second});
            }
        }

        pair<int, int> tmp;
        bool found = false;
        while (!q.empty()) {
            tmp = q.top(); q.pop();

            if (!vis[tmp.second]) {
                found = true;
                break;
            }
        }

        if (!found) break;
        cur = tmp.second;
        dist[cur] = tmp.first;
        vis[cur] = true;
        cnt++;
    }

    for (int i = 1; i <= n; i++) {
        cout << (dist[i] == MAX ? "INF" : to_string(dist[i])) << '\n';
    }
}
