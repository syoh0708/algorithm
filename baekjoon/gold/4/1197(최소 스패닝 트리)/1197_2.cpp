#include <bits/stdc++.h>

using namespace std;

int n, m, ans, cnt;
vector<tuple<int, int, int>> e;
int group[10005];

int find(int a) {
    if (group[a] == a) return a;

    return group[a] = find(group[a]);
}

bool is_same_group(int a, int b) {
    int aa = find(a), bb = find(b);
    if (aa == bb) return true;
    else if (aa > bb) swap(aa, bb);

    group[bb] = aa;

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, cost; cin >> u >> v >> cost;

        e.push_back({cost, u, v});
    }

    sort(e.begin(), e.end());
    for (int i = 1; i <= n; i++) group[i] = i;

    int i = 0;

    while (cnt < n - 1) {
        int cost, u, v;

        tie(cost, u, v) = e[i++];

        if (is_same_group(u, v)) continue;

        cnt++;
        ans += cost;
    }

    cout << ans;
}
