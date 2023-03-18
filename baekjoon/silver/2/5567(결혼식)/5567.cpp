#include <bits/stdc++.h>

using namespace std;

vector<int> e[501];
bool vis[501];
int n, m, ans = -1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    while (m--) {
        int u, v; cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    queue<pair<int, int>> q;
    q.push({1, 0});
    vis[1] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        if (cur.second >= 3) break;

        ans++;

        for (int next : e[cur.first]) {
            if (vis[next]) continue;
            vis[next] = true;

            q.push({next, cur.second + 1});
        }
    }

    cout << ans;
}
