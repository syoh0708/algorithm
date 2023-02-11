#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int f, s, g, u, d;

    cin >> f >> s >> g >> u >> d;

    vector<bool> visited(f + 1);
    queue<pair<int, int>> q;

    q.push({s, 0});
    visited[s] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        
        if (cur.first == g) {
            cout << cur.second;
            return 0;
        }

        if (cur.first + u <= f && !visited[cur.first + u]) {
            q.push({cur.first + u, cur.second + 1});
            visited[cur.first + u] = true;
        }

        if (cur.first - d > 0 && !visited[cur.first - d]) {
            q.push({cur.first - d, cur.second + 1});
            visited[cur.first - d] = true;
        }
    }

    cout << "use the stairs";
}
