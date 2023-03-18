#include <bits/stdc++.h>

using namespace std;

vector<int> e[1001];
vector<bool> visited(1001);

void dfs(int u) {
    for (int v : e[u]) {
        if (visited[v]) continue;

        visited[v] = true;
        dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, ans = 0; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;

        e[x].push_back(y);
        e[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;

        visited[i] = true;
        ans++;
        dfs(i);
    }

    cout << ans;
}
