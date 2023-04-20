#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX = 1'000'000'000'000'000'000;
ll n, m;
vector<pair<ll, ll>> e[100'005];
bool vis[100'005];
ll d[100'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        
        e[u].push_back({i, v});
        e[v].push_back({i, u});
    }

    fill(d + 1, d + n + 1, MAX);

    priority_queue<
        pair<ll, ll>,
        vector<pair<ll, ll>>,
        greater<pair<ll, ll>>
    > q;

    q.push({0, 1});
    d[1] = 0;

    while (!q.empty()) {
        ll t, v;

        tie(t, v) = q.top(); q.pop();

        if (d[v] != t) continue;
        if (v == n) {
            cout << t;
            return 0;
        }

        for (auto edge : e[v]) {
            ll nv = edge.second;
            ll i = edge.first;
            ll nt = (t / m) * m + i + 1;

            if (t % m > i) nt += m;
            if (d[nv] < nt) continue;

            d[nv] = nt;
            q.push({d[nv], nv});
        }
    }
}
