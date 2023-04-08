#include <bits/stdc++.h>

using namespace std;

int n, ans;
vector<int> e1[10005];
vector<int> e2[10005];
int ind[10005];
int dur[10005];
int en[10005];
queue<int> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int t, c; cin >> t >> c;

        dur[i] = t;

        while (c--) {
            int a; cin >> a;

            e1[a].push_back(i);
            e2[i].push_back(a);
            ind[i]++;
        }
    }

    for (int i = 1; i <= n; i++)
        if (!ind[i]) q.push(i);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int a : e2[cur]) en[cur] = max(en[cur], en[a]);
        for (int a : e1[cur]) {
            ind[a]--;
            if (!ind[a]) q.push(a);
        }

        en[cur] += dur[cur];
        ans = max(ans, en[cur]);
    }

    cout << ans;
}
