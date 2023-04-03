#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000'000;
int n, m, x, ans;
vector<pair<int, int>> e[2][1005];
int d[2][1005];
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq[2];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x;

    while (m--) {
        int u, v, w; cin >> u >> v >> w;

        e[0][u].push_back({w, v});
        e[1][v].push_back({w, u});
    }

    fill(d[0] + 1, d[0] + n + 1, MAX);
    fill(d[1] + 1, d[1] + n + 1, MAX);

    for (int i = 0; i < 2; i++) {
        d[i][x] = 0;
        pq[i].push({0, x});

        while (!pq[i].empty()) {
            int cur_d, cur;
            
            tie(cur_d, cur) = pq[i].top(); pq[i].pop();

            if (d[i][cur] != cur_d) continue;

            for (auto a : e[i][cur]) {
                int nxt_d = a.first;
                int nxt = a.second;

                if (cur_d + nxt_d < d[i][nxt]) {
                    d[i][nxt] = cur_d + nxt_d;
                    pq[i].push({d[i][nxt], nxt});
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        ans = max(ans, d[0][i] + d[1][i]);
    }

    cout << ans;
}
