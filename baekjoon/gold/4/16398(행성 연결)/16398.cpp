#include <bits/stdc++.h>

using namespace std;

long long ans;
int n, cnt;
int group[1005];
int rnk[1005];
vector<tuple<int, int, int>> e;

int find(int x) {
    if (x == group[x]) return x;

    return group[x] = find(group[x]);
}

bool is_same_group(int x, int y) {
    x = find(x);
    y = find(y);

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

    cin >> n;

    for (int i = 0; i < n; i++) {
        group[i] = i;
        for (int j = 0; j < n; j++) {
            int cost; cin >> cost;

            if (i >= j) continue;

            e.push_back({cost, i, j});
        }
    }

    sort(e.begin(), e.end());

    for (int i = 0; i < e.size(); i++) {
        int cost, x, y;

        tie(cost, x, y) = e[i];

        if (is_same_group(x, y)) continue;

        ans += cost;
        cnt++;
        
        if (cnt == n - 1) break;
    }

    cout << ans;
}
