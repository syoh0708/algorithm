#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000'000;
int n, m;
int adj[105][105];
int nxt[105][105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)  {
        fill(adj[i] + 1, adj[i] + n + 1, MAX);
    }
    
    while (m--) {
        int a, b, c; cin >> a >> b >> c;

        adj[a][b] = min(adj[a][b], c);
        nxt[a][b] = b;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (i == j || k == i || k == j) continue;
                if (adj[i][k] + adj[k][j] < adj[i][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (adj[i][j] == MAX ? 0 : adj[i][j]) << ' ';
        }
        cout << '\n';
    }
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (adj[i][j] == MAX) {
                cout << 0 << '\n';
                continue;
            }

            vector<int> path;
            int cur = i;
            path.push_back(cur);
            while (cur != j) {
                cur = nxt[cur][j];
                path.push_back(cur);
            }

            cout << path.size() << ' ';
            for (int a : path) cout << a << ' ';
            cout << '\n';
        }
}
