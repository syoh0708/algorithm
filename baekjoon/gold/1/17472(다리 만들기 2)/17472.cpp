#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000'000;
int n, m, cnt, ans, island;
int g[12];
int b[10][10];
int dist[12][12];
bool vis[12][12];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<tuple<int, int, int>> v;

int find(int x) {
    if (g[x] == x) return x;

    return g[x] = find(g[x]);
}

bool is_same_group(int x, int y) {
    x = find(x); y = find(y);

    if (x == y) return true;

    g[x] = y;

    return false;
}

void name_island() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] || !b[i][j]) continue;

            vis[i][j] = true;
            b[i][j] = ++island;

            queue<pair<int, int>> q;
            q.push({i, j});

            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || !b[nx][ny]) continue;

                    vis[nx][ny] = true;
                    b[nx][ny] = island;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> b[i][j];

    name_island();

    for (int i = 1; i <= island; i++) {
        g[i] = i;
        fill(dist[i] + 1, dist[i] + island + 1, MAX);
    }

    for (int i = 0; i < n; i++) {
        int j = 0, st, en;

        while (j < m) {
            while (j < m && !b[i][j]) j++;
            while (j < m && b[i][j]) j++;
            if (j == m) break;            

            st = j - 1;

            while (j < m && !b[i][j]) j++;
            if (j == m) break;
            en = j;
            if (en - st > 2) {
                dist[b[i][st]][b[i][en]] = min(dist[b[i][st]][b[i][en]], en - st - 1);
                dist[b[i][en]][b[i][st]] = min(dist[b[i][en]][b[i][st]], en - st - 1);
            }
        }
    }

    for (int j = 0; j < m; j++) {
        int i = 0, st, en;

        while (i < n) {
            while (i < n && !b[i][j]) i++;
            while (i < n && b[i][j]) i++;
            if (i == n) break;            

            st = i - 1;

            while (i < n && !b[i][j]) i++;
            if (i == n) break;
            en = i;
            if (en - st > 2) {
                dist[b[st][j]][b[en][j]] = min(dist[b[st][j]][b[en][j]], en - st - 1);
                dist[b[en][j]][b[st][j]] = min(dist[b[en][j]][b[st][j]], en - st - 1);
            }
        }
    }

    for (int i = 1; i <= island; i++)
        for (int j = i + 1; j <= island; j++)
            if (dist[i][j] != MAX) v.push_back({dist[i][j], i, j});

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        auto [d, x, y] = v[i];

        if (is_same_group(x, y)) continue;

        ans += d;
        cnt++;
    }

    if (cnt == island - 1) cout << ans;
    else cout << -1;
}

// 4명 승률 40%
// 0.4 * 300 + 0.6 * -100
// 120 - 60 = 60
// 2명 승률 70%
// 0.7 * 100 + 0.3 * -100
// 70 - 30 = 40