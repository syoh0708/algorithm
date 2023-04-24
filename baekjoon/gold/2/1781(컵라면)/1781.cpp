#include <bits/stdc++.h>

using namespace std;

int n, ans;
pair<int, int> a[200005];
priority_queue<int> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n, greater<pair<int, int>>());


    int i = 0;
    for (int t = n; t > 0; t--) {
        while (a[i].first == t) q.push(a[i++].second);

        if (q.empty()) continue;

        ans += q.top(); q.pop();
    }

    cout << ans;
}
