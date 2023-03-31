#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000'000;
int n, m;
int adj[105][105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) fill(adj[i], adj[i] + n, MAX);
    
    while (m--) {
        int a, b, c; cin >> a >> b >> c;

        adj[a - 1][b - 1] = min(adj[a - 1][b - 1], c);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            for (int k = 0; k < n; k++) {
                if (i == k || j == k) continue;

                adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << (adj[i][j] == MAX ? 0 : adj[i][j]) << ' ';

        cout << '\n';
    }
}
