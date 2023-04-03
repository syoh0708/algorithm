#include <bits/stdc++.h>

using namespace std;

const int MAX = 100'000'000;
int n, m, ans = MAX;
vector<pair<int, int>> e[805];
int d[3][805];
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq[3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while (m--) {
        int u, v, w; cin >> u >> v >> w;

        e[u].push_back({w, v});
        e[v].push_back({w, u});
    }

    int v1, v2; cin >> v1 >> v2;

    int st[3] = {1, v1, v2};
    for (int i = 0; i < 3; i++) {
        fill(d[i] + 1, d[i] + n + 1, MAX);
    }

    for (int i = 0; i < 3; i++) {
        pq[i].push({0, st[i]});
        d[i][st[i]] = 0;

        while (!pq[i].empty()) {
            int cur_d, cur;

            tie(cur_d, cur) = pq[i].top(); pq[i].pop();

            if (cur_d != d[i][cur]) continue;

            for (auto x : e[cur]) {
                int nxt_d = x.first;
                int nxt = x.second;

                if (cur_d + nxt_d < d[i][nxt]) {
                    d[i][nxt] = cur_d + nxt_d;
                    pq[i].push({d[i][nxt], nxt});
                }
            }
        }
    }

    ans = min(ans, d[0][v1] + d[1][v2] + d[2][n]);
    ans = min(ans, d[0][v2] + d[2][v1] + d[1][n]);
    cout << (ans == MAX ? -1 : ans);
}
