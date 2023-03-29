#include <bits/stdc++.h>

using namespace std;

int n, m, cnt, ans;
int group[100005];
int rnk[100005];
vector<tuple<int, int, int>> v;

int find(int x) {
    if (x == group[x]) return x;

    return group[x] = find(group[x]);
}

bool is_same_group(int x, int y) {
    x = find(x); y = find(y);

    if (x == y) return true;

    if (rnk[x] > rnk[y]) group[y] = x;
    else {
        group[x] = y;

        if (rnk[x] == rnk[y]) rnk[x]++;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, cost; cin >> a >> b >> cost;

        v.push_back({cost, a, b});
    }

    for (int i = 1; i <= n; i++) group[i] = i;

    sort(v.begin(), v.end());

    for (size_t i = 0; i < m; i++) {
        if (cnt == n - 2) break;

        int a, b, cost;

        tie(cost, a, b) = v[i];

        if (is_same_group(a, b)) continue;

        ans += cost;
        cnt++;
    }

    cout << ans;
}
