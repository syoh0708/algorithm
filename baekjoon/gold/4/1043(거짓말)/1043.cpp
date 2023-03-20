#include <bits/stdc++.h>

using namespace std;

bool truth[51];
int party[51][51];
bool adj[51][51];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> v;
    int n, m, t, ans = 0; cin >> n >> m >> t;

    for (int i = 0; i < t; i++) {
        int a; cin >> a;
        truth[a] = true;
        v.push_back(a);
    }

    for (int i = 0; i < m; i++) {
        int l; cin >> l;

        for (int j = 0; j < l; j++) {
            cin >> party[i][j];
        }

        for (int j = 1; j < n; j++) {
            adj[party[i][j]][party[i][j - 1]] = true;
            adj[party[i][j - 1]][party[i][j]] = true;
        }
    }

    for (int a : v) {
        queue<int> q;
        q.push(a);

        while (!q.empty()) {
            int cur = q.front(); q.pop();

            for (int i = 1; i <= n; i++) {
                if (!adj[cur][i] || truth[i]) continue;

                truth[i] = true;
                q.push(i);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        ans++;
        for (int j = 0; j < 50; j++) {
            if (!party[i][j]) break;

            if (truth[party[i][j]]) {
                ans--;
                break;
            }
        }
    }

    cout << ans;
}
