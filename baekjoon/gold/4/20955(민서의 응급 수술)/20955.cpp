#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
vector<int> e[100005];
vector<bool> vis(100005);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while (m--) {
        int u, v; cin >> u >> v;
        
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int c_cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;

        c_cnt++;

        int v_cnt = 0, e_cnt = 0;
        queue<int> q;

        vis[i] = true;
        v_cnt++;
        q.push(i);

        while (!q.empty()) {
            int cur = q.front(); q.pop();

            for (int nxt : e[cur]) {
                e_cnt++;
                if (vis[nxt]) continue;

                vis[nxt] = true;
                v_cnt++;
                q.push(nxt);
            }
        }

        e_cnt /= 2;
        ans += (e_cnt + 1 - v_cnt);
    }

    ans += (c_cnt - 1);

    cout << ans;
}
