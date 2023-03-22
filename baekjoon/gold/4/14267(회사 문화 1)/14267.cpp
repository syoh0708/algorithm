#include <bits/stdc++.h>

using namespace std;

int n, m;
int ap[100005];
vector<int> e[100005];

void dfs(int cur, int score) {
    if (ap[cur]) score += ap[cur];

    ap[cur] = score;
    for (int nxt : e[cur]) {
        dfs(nxt, score);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int a; cin >> a;

        if (i == 1) continue;
        e[a].push_back(i);
    }

    while (m--) {
        int i, w; cin >> i >> w;

        ap[i] += w;
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << ap[i] << ' ';
    }
}
