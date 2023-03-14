#include <bits/stdc++.h>

using namespace std;

int a[52];

class Cmp {
public:
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.first * (b.second + 1) < b.first * (a.second + 1);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> q;
    int n, m, l; cin >> n >> m >> l;

    for (int i = 0; i < n; i++) {
        cin >> a[i + 1];
    }
    a[0] = 0;
    a[n + 1] = l;

    sort(a, a + n + 2);

    for (int i = 0; i <= n; i++) {
        q.push({a[i + 1] -  a[i], 0});
    }

    for (int i = 0; i < m; i++) {
        pair<int, int> cur = q.top(); q.pop();
        q.push({cur.first, cur.second + 1});
    }

    pair<int, int> max_dist = q.top();
    cout << (max_dist.first - 1) / (max_dist.second + 1) + 1;
}
