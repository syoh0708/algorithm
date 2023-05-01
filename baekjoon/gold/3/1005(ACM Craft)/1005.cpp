#include <bits/stdc++.h>

using namespace std;

int t, n, k, w;
int d[1005];
vector<int> e[1005];
int dur[1005];

int solve(int cur) {
    if (dur[cur] >= 0) return dur[cur];

    int ans = 0;

    for (int nxt : e[cur]) ans = max(ans, solve(nxt));

    return dur[cur] = ans + d[cur];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> k;

        fill(dur, dur + 1005, -1);
        for (int i = 1; i <= n; i++) cin >> d[i];

        while (k--) {
            int u, v; cin >> u >> v;
            
            e[v].push_back(u);
        }

        cin >> w;

        cout << solve(w) << '\n';

        for (int i = 1; i <= n; i++) {
            e[i].clear();
        }
    }
}
