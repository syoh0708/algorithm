#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000'000;
int n, m, src, dest;
int d[1005];
int pre[1005];
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

    cin >> src >> dest;

    fill(pre + 1, pre + n + 1, -1);
    fill(d + 1, d + n + 1, MAX);
    pq.push({0, src});
    d[src] = 0;

    while (!pq.empty()) {
        int cur_dist, cur, nxt_dist, nxt;

        tie(cur_dist, cur) = pq.top(); pq.pop();

        if (cur_dist != d[cur]) continue;

        for (auto a : e[cur]) {
            nxt_dist = a.first;
            nxt = a.second;

            if (cur_dist + nxt_dist < d[nxt]) {
                d[nxt] = cur_dist + nxt_dist;
                pq.push({d[nxt], nxt});
                pre[nxt] = cur;
            }
        }
    }

    cout << d[dest] << '\n';

    vector<int> path;
    int cur = dest;
    path.push_back(cur);
    while (pre[cur] != -1) {
        cur = pre[cur];
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for (int a : path) cout << a << ' ';
}
