#include <bits/stdc++.h>

using namespace std;

int n, m, ans, digit;
queue<pair<int, int>> q;
bool vis[1'000'005];

int change_digit(int k, int d) {
    int tmp = 1 << d;

    return k ^ tmp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while (m--) {
        int a; cin >> a;

        q.push({a, 0});
    }

    int tmp = n;
    while (tmp) {
        digit++;
        tmp /= 2;
    }

    while (!q.empty()) {
        int cur, dist;

        tie(cur, dist) = q.front(); q.pop();
        if (dist > ans) ans = dist;

        for (int i = 0; i < digit; i++) {
            int nxt = change_digit(cur, i);

            if (nxt > n || vis[nxt]) continue;

            vis[nxt] = true;
            q.push({nxt, dist + 1}); 
        }
    }

    cout << ans;
}
