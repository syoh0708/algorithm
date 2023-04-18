#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

double ans;
int n, m;
pair<ll, ll> pos[1005];
vector<tuple<ll, ll, ll>> e;
int g[1005];

int find(int x) {
    if (x == g[x]) return x;

    return g[x] = find(g[x]);
}

bool is_same_group(int x, int y) {
    x = find(x); y = find(y);

    if (x == y) return true;

    g[x] = y;

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> pos[i].first >> pos[i].second;
        g[i] = i;
    }

    while (m--) {
        int u, v; cin >> u >> v;

        is_same_group(u, v);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            e.push_back({(pos[i].first - pos[j].first) * (pos[i].first - pos[j].first) + (pos[i].second - pos[j].second) * (pos[i].second - pos[j].second), i, j});
        }
    }

    sort(e.begin(), e.end());

    for (auto i = 0; i < e.size(); i++) {
        ll dist, u, v;

        tie(dist, u, v) = e[i];

        if (is_same_group(u, v)) continue;

        ans += sqrt(dist);
    }

    cout << fixed;
    cout.precision(2);
    cout << ans;
}
