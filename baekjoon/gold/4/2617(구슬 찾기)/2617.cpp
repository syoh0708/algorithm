#include <bits/stdc++.h>

using namespace std;

vector<int> e1[100];
vector<int> e2[100];
bool not_mid[100];
int h1[100];
int h2[100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, ans = 0; cin >> n >> m;

    while (m--) {
        int u, v; cin >> u >> v;

        e1[u].push_back(v);
        e2[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        queue<int> q;
        bool vis[100] = {};
        q.push(i);
        vis[i] = true;

        while (!q.empty()) {
            int cur = q.front(); q.pop();

            for (int next : e1[cur]) {
                if (vis[next]) continue;

                vis[next] = true;
                q.push(next);
                cnt++;
            }
        }

        if (cnt > n / 2) {
            ans++;
            continue;
        }

        cnt = 0;
        fill(vis, vis + 100, false);
        q.push(i);
        vis[i] = true;

        while (!q.empty()) {
            int cur = q.front(); q.pop();

            for (int next : e2[cur]) {
                if (vis[next]) continue;

                vis[next] = true;
                q.push(next);
                cnt++;
            }
        }

        if (cnt > n / 2) ans++;
    }

    cout << ans;
}
