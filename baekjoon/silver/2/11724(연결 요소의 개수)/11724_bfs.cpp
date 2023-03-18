#include <bits/stdc++.h>

using namespace std;

vector<int> e[1001];
bool visited[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, ans = 0; cin >> n >> m;

    while (m--) {
        int u, v; cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;

        ans++;
        queue<int> q;

        q.push(i);
        visited[i] = true;

        while (!q.empty()) {
            int cur = q.front(); q.pop();

            for (int nxt : e[cur]) {
                if (visited[nxt]) continue;

                q.push(nxt);
                visited[nxt] = true;
            }
        }
    }

    cout << ans;
}
