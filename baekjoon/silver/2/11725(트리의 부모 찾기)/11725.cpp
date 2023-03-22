#include <bits/stdc++.h>

using namespace std;

vector<int> e[100001];
int p[100001];

void dfs(int a, int par) {
    p[a] = par;

    for (int next : e[a]) {
        if (next == par) continue;

        dfs(next, a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 2; i <= n; i++) {
        cout << p[i] << '\n';
    }
}
