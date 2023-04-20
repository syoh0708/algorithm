#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000'000;
int n, ans = MAX;
int p[14];
vector<int> e[15];

bool is_valid(int x) {
    bool team[11] = {};
    bool vis[11] = {};
    int cnt = 0;

    int tmp = x;

    for (int i = 1; i <= n; i++) {
        team[i] = tmp % 2;

        tmp /= 2;
    }

    int a = 1, b;
    for (int i = 2; i <= n; i++) {
        if (team[a] == team[i]) continue;

        b = i;
        break;
    }

    queue<int> q;

    q.push(a);
    vis[a] = true;
    cnt++;
    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int nxt : e[cur]) {
            if (vis[nxt] || team[a] != team[nxt]) continue;

            vis[nxt] = true;
            cnt++;
            q.push(nxt);
        }
    }

    q.push(b);
    vis[b] = true;
    cnt++;
    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int nxt : e[cur]) {
            if (vis[nxt] || team[b] != team[nxt]) continue;

            vis[nxt] = true;
            cnt++;
            q.push(nxt);
        }
    }

    return cnt == n;
}

int pop_diff(int x) {
    int diff = 0;

    for (int i = 1; i <= n; i++) {
        if (x % 2) diff += p[i];
        else diff -= p[i];

        x /= 2;
    }

    return abs(diff);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) {
        int cnt; cin >> cnt;

        while (cnt--) {
            int u; cin >> u;

            e[i].push_back(u);
        }
    }

    for (int i = (1 << (n - 1)); i < (1 << n) - 1; i++) {
        if (is_valid(i)) {
            ans = min(ans, pop_diff(i));
        }
    }

    cout << (ans == MAX ? -1 : ans);
}
