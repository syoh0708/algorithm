#include <bits/stdc++.h>

using namespace std;

int adj[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        vector<bool> vis(n + 1, false);
        queue<int> q;

        q.push(i);

        while (!q.empty()) {
            int cur = q.front(); q.pop();

            for (int j = 0; j < n; j++) {
                if (vis[j] || adj[cur][j] == 0) continue;

                vis[j] = true;
                adj[i][j] = true;
                q.push(j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }
}
