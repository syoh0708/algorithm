#include <bits/stdc++.h>

using namespace std;

vector<int> e[51];
vector<pair<int, int>> scores;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;

    while (1) {
        int u, v; cin >> u >> v;

        if (u == -1 && v == -1) break;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        bool vis[51] = {};
        queue<pair<int, int>> q;
        int score;

        q.push({i, 0});
        vis[i] = true;
        while (!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();
            score = cur.second;

            for (auto next : e[cur.first]) {
                if (vis[next]) continue;

                vis[next] = true;
                q.push({next, cur.second + 1});
            }
        }

        scores.push_back({score, i});
    }

    sort(scores.begin(), scores.end());

    int min_score = scores[0].first;
    int cnt = 0;

    for (int i = 0; i < scores.size(); i++) {
        if (scores[i].first != min_score) break;
        cnt++;
    }

    cout << min_score << ' ' << cnt << '\n';

    for (int i = 0; i < cnt; i++) {
        cout << scores[i].second << ' ';
    }
}
