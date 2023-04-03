#include <bits/stdc++.h>

using namespace std;

const int MAX = 100'000'000;
int n, m, v1, v2, dist = MAX;
int adj[805][805];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        fill(adj[i] + 1, adj[i] + n + 1, MAX);
        adj[i][i] = 0;
    }

    while (m--) {
        int u, v, w; cin >> u >> v >> w;

        adj[u][v] = w;
        adj[v][u] = w;
    }
    
    cin >> v1 >> v2;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (adj[i][k] + adj[k][j] < adj[i][j]) adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }

    dist = min(dist, adj[1][v1] + adj[v1][v2] + adj[v2][n]);
    dist = min(dist, adj[1][v2] + adj[v2][v1] + adj[v1][n]);

    cout << (dist == MAX ? -1 : dist);
}
