#include <bits/stdc++.h>

using namespace std;

int n, cnt;
long long ans;
int adj[1005][1005];
bool vis[1005];
priority_queue<
    tuple<int, int, int>,
    vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>>
> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    vis[0] = true;
    cnt = 1;
    for (int i = 1; i < n; i++)
        q.push({adj[0][i], 0, i});
    
    while (cnt < n) {
        int cost, i, j;

        tie(cost, i, j) = q.top(); q.pop();

        if (vis[j]) continue;
        vis[j] = true;
        cnt++;
        ans += cost;

        for (int k = 0; k < n; k++) {
            if (vis[k]) continue;

            q.push({adj[j][k], j, k});
        } 

    }

    cout << ans;
}
