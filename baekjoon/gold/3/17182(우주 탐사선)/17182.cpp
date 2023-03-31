#include <bits/stdc++.h>

using namespace std;

int n, k, cur, ans = 1'000'000'000;
int adj[12][12];

int func(vector<int>& order) {
    int t = 0, i = 0, cur = k, nxt = order[i];

    while (i++ < n - 1) {
        t += adj[cur][nxt];
        cur = nxt;
        nxt = order[i];
    }
    
    return t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];
        
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    vector<int> order;
    for (int i = 0; i < n; i++) {
        if (i == k) continue;

        order.push_back(i);
    }

    do {
        ans = min(ans, func(order));
    } while (next_permutation(order.begin(), order.end()));

    cout << ans;
}
