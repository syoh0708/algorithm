#include <bits/stdc++.h>

using namespace std;

int n, ans, cnt;
pair<int, int> x[100005];
pair<int, int> y[100005];
pair<int, int> z[100005];
vector<pair<int, int>> e[100005];
bool vis[100005]; 

priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i].first >> y[i].first >> z[i].first;
        
        x[i].second = i;
        y[i].second = i;
        z[i].second = i;
    }
    
    sort(x, x + n);
    sort(y, y + n);
    sort(z, z + n);

    for (int i = 0; i < n - 1; i++) {
        e[x[i].second].push_back({x[i + 1].first - x[i].first, x[i + 1].second});
        e[x[i + 1].second].push_back({x[i + 1].first - x[i].first, x[i].second});
        e[y[i].second].push_back({y[i + 1].first - y[i].first, y[i + 1].second});
        e[y[i + 1].second].push_back({y[i + 1].first - y[i].first, y[i].second});
        e[z[i].second].push_back({z[i + 1].first - z[i].first, z[i + 1].second});
        e[z[i + 1].second].push_back({z[i + 1].first - z[i].first, z[i].second});
    }

    vis[0] = true;
    for (auto cur : e[0]) q.push(cur);

    while (cnt < n - 1) {
        auto cur = q.top(); q.pop();
        
        if (vis[cur.second]) continue;

        vis[cur.second] = true;
        cnt++;
        ans += cur.first;
        for (auto nxt : e[cur.second]) {
            if (!vis[nxt.second]) q.push(nxt);
        }
    }

    cout << ans;
}
