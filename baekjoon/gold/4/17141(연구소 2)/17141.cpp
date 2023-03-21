#include <bits/stdc++.h>

using namespace std;

int n, m, min_t = 10000;
bool wall[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    vector<pair<int, int>> v;
    vector<int> order;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a; cin >> a;

            if (a == 2) v.push_back({i, j});
            else wall[i][j] = a;
        }
    }

    for (int i = 0; i < v.size(); i++) {
        if (i < v.size() - m) order.push_back(0);
        else order.push_back(1);
    }

    do {
        bool vis[51][51] = {};
        int t = 0;
        queue<tuple<int, int, int>> q;

        for (int i = 0; i < order.size(); i++) {
            if (order[i]) {
                q.push({v[i].first, v[i].second, 0});
                vis[v[i].first][v[i].second] = true;
            }
        }

        while (!q.empty()) {
            int x, y, d;
            tie(x, y, d) = q.front(); q.pop();
            t = max(t, d);

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (vis[nx][ny] || wall[nx][ny]) continue;

                vis[nx][ny] = true;
                q.push({nx, ny, d + 1});
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && !wall[i][j]) t = 10000;
            }
        }

        min_t = min(min_t, t);
        
    } while (next_permutation(order.begin(), order.end()));

    cout << (min_t == 10000 ? -1 : min_t);
}
