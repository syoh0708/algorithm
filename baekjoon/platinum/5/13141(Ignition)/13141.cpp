#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000'000;
int n, m, ans = MAX;
int mx[205][205];
int d[205][205];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        fill(d[i] + 1, d[i] + n + 1, MAX);
        d[i][i] = 0;
    }

    while (m--) {
        int u, v, w; cin >> u >> v >> w;

        if (u > v) swap(u, v);

        mx[u][v] = max(mx[u][v], 2 * w);
        d[u][v] = min(d[u][v], 2 * w);
        d[v][u] = min(d[v][u], 2 * w);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    
    for (int st = 1; st <= n; st++) {
        int time = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                int ti = d[st][i], tj = d[st][j];

                if (ti > tj) swap(ti, tj);

                if (mx[i][j] <= tj - ti) time = max(time, ti + mx[i][j]);
                else time = max(time, (ti + tj + mx[i][j]) / 2);
            }
        }

        ans = min(ans, time);
    }

    cout << fixed;
    cout.precision(1);
    cout << ((double) ans) / 2;
}
