#include <bits/stdc++.h>

using namespace std;

vector<int> e[1001];
vector<bool> visited(1001);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, ans = 0; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;

        stack<int> s;
        ans++;
        s.push(i);

        while (!s.empty()) {
            int cur = s.top(); s.pop();

            if (visited[cur]) continue;
            visited[cur] = true;

            for (int next : e[cur]) {
                if (visited[next]) continue;

                s.push(next);
            }
        }
    }

    cout << ans;
}
