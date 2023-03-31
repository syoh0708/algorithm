#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000'000;
int ans = MAX;
int adj[405][405];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; i++) fill(adj[i] + 1, adj[i] + n + 1, MAX);


    while (m--) {
        int a, b, c; cin >> a >> b >> c;

        adj[a][b] = c;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    for (int i = 1; i <= n; i++)
        ans = min(ans, adj[i][i]);

    cout << (ans == MAX ? -1 : ans);
}
