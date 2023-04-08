#include <bits/stdc++.h>

using namespace std;

int n, ans, cnt;
int g[100005];
int rnk[100005];
pair<int, int> x[100005];
pair<int, int> y[100005];
pair<int, int> z[100005];

int find(int x) {
    if (x == g[x]) return x;

    return g[x] = find(g[x]);
}

bool is_same_group(int a, int b) {
    a = find(a); b = find(b);

    if (a == b) return true;

    if (rnk[a] < rnk[b]) {
        g[a] = b;
    } else {
        g[b] = a;

        if (rnk[a] == rnk[b]) rnk[b]++;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i].first >> y[i].first >> z[i].first;
        
        x[i].second = i;
        y[i].second = i;
        z[i].second = i;
        g[i] = i;
    }
    
    sort(x, x + n);
    sort(y, y + n);
    sort(z, z + n);

    vector<tuple<int, int, int>> v;

    for (int i = 0; i < n - 1; i++) {
        v.push_back({x[i + 1].first - x[i].first, x[i].second, x[i + 1].second});
        v.push_back({y[i + 1].first - y[i].first, y[i].second, y[i + 1].second});
        v.push_back({z[i + 1].first - z[i].first, z[i].second, z[i + 1].second});
    }

    sort(v.begin(), v.end());

    for (auto cur : v) {
        int a, b, d;
        
        tie(d, a, b) = cur;

        if (is_same_group(a, b)) continue;

        ans += d;
        cnt++;
        
        if (cnt == n - 1) break;
    }

    cout << ans;
}
