#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX = 1'000'000'000'000;
int n, m, k;
vector<int> place;
vector<pair<ll, int>> e[100'005];
ll d[100'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    while (m--) {
        int u, v, c; cin >> u >> v >> c;
        
        e[v].push_back({c, u});
    }

    for (int i = 0; i < k; i++) {
        int a; cin >> a;

        place.push_back(a);
    }

    fill(d + 1, d + n + 1, MAX);

    for (int p : place) {
        d[p] = 0;
        priority_queue<
            pair<ll, int>,
            vector<pair<ll, int>>,
            greater<pair<ll, int>>
        > q;

        q.push({0, p});

        while (!q.empty()) {
            auto [cur_dist, cur] = q.top(); q.pop();

            if (cur_dist > d[cur]) continue;
            for (int i = 0; i < e[cur].size(); i++) {
                ll nxt_dist = e[cur][i].first;
                int nxt = e[cur][i].second;

                if (nxt_dist + d[cur] < d[nxt]) {
                    d[nxt] = nxt_dist + d[cur];
                    q.push({d[nxt], nxt});
                }
            }
        }
    }

    int city = 1;
    ll max_dist = 0;

    for (int i = 1; i <= n; i++) {
        if (d[i] > max_dist) {
            city = i;
            max_dist = d[i];
        }
    }

    cout << city << '\n' << max_dist;
}
