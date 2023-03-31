#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000;
int n, m, r, ans;
int item[105];
int adj[105][105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++) {
        cin >> item[i];
        fill(adj[i] + 1, adj[i] + n + 1, MAX);
        adj[i][i] = 0;
    }

    while (r--) {
        int a, b, c; cin >> a >> b >> c;
        adj[a][b] = c;
        adj[b][a] = c;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        for (int j = 1; j <= n; j++)
            if (adj[i][j] <= m) tmp += item[j];

        ans = max(ans, tmp);
    }
    cout << ans;
}
