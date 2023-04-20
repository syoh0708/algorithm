#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000'000;
int n, m, s, d;
vector<pair<int, int>> e[2][505];
int dijk[2][505];

void dijkstra(int s, int d, int idx) {
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > q;
    fill(dijk[idx], dijk[idx] + n, MAX);
    
    dijk[idx][s] = 0;
    q.push({dijk[idx][s], s});

    while (!q.empty()) {
        int d, v;

        tie(d, v) = q.top(); q.pop();

        if (d > dijk[idx][v]) continue;

        for (auto nxt : e[idx][v]) {
            if (dijk[idx][nxt.second] <= d + nxt.first) continue;

            dijk[idx][nxt.second] = d + nxt.first;

            q.push({dijk[idx][nxt.second], nxt.second});
        } 
    }
}

void remove_edges(int cur, int cur_dist) {
    int sz = e[0][cur].size();

    for (int i = sz - 1; i >= 0; i--) {
        int nxt, nxt_dist;
        tie(nxt_dist, nxt) = e[0][cur][i];
        if (nxt_dist + dijk[1][nxt] == cur_dist) {
            e[0][cur].erase(e[0][cur].begin() + i);
            remove_edges(nxt, dijk[1][nxt]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> n >> m;

        if (n == 0 && m == 0) return 0;

        cin >> s >> d;

        while (m--) {
            int u, v, w; cin >> u >> v >> w;

            e[0][u].push_back({w, v});
            e[1][v].push_back({w, u});
        }

        dijkstra(d, s, 1);
        remove_edges(s, dijk[1][s]);
        dijkstra(s, d, 0);

        cout << (dijk[0][d] == MAX ? -1 : dijk[0][d]) << '\n';
        for (int i = 0; i < n; i++) {
            e[0][i].clear();
            e[1][i].clear();
        }
    }
}
