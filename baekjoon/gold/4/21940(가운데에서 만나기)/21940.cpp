#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000;
int n, m, k, min_t = 1'000'000'000;
int adj[205][205];
int t[205];
vector<int> fr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        fill(adj[i] + 1, adj[i] + n + 1, MAX);
        adj[i][i] = 0;
    }
    fill(t + 1, t + n + 1, min_t);

    while (m--) {
        int a, b, c; cin >> a >> b >> c;

        adj[a][b] = c;
    }

    cin >> k;

    for (int i = 0; i < k; i++) {
        int a; cin >> a;
        fr.push_back(a);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);   
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int max_t = 0;
        for (int c : fr) max_t = max(max_t, adj[c][i] + adj[i][c]);
        t[i] = max_t;

        min_t = min(min_t, max_t);
    }

    for (int i = 1; i <= n; i++)
        if (t[i] == min_t) cout << i << ' ';
}
