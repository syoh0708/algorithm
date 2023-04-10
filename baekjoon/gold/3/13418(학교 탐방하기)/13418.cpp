#include <bits/stdc++.h>

using namespace std;

int n, m, min_d, max_d;
vector<tuple<int, int, int>> e1;
vector<tuple<int, int, int>> e2;
int g[1005];

int find(int x) {
    if (x == g[x]) return x;

    return g[x] = find(g[x]);
}

bool is_same_group(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return true;

    g[x] = y;

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    m++;

    for (int i = 0; i <= n; i++) g[i] = i;

    while (m--) {
        int u, v, w; cin >> u >> v >> w;

        e1.push_back({1 - w, u, v});
        e2.push_back({w, u, v});
    }

    sort(e1.begin(), e1.end());
    sort(e2.begin(), e2.end());

    int cnt = 0;

    for (auto cur : e1) {
        int u, v, w;

        tie(w, u, v) = cur;

        if (is_same_group(u, v)) continue;

        min_d += w;
        cnt++;

        if (cnt == n) break;
    }

    for (int i = 0; i <= n; i++) g[i] = i;
    cnt = 0;

    for (auto cur : e2) {
        int u, v, w;

        tie(w, u, v) = cur;

        if (is_same_group(u, v)) continue;

        max_d += w;
        cnt++;

        if (cnt == n) break;
    }

    max_d = n - max_d;

    cout << (max_d + min_d) * (max_d - min_d);
}
