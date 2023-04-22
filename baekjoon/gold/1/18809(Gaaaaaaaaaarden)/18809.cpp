#include <bits/stdc++.h>

using namespace std;

int n, m, g, r, ans;
bool b[52][52];
vector<pair<int, int>> cand;
vector<int> order;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solve(vector<int>& order) {
    int cnt = 0;
    pair<int, int> tmp[52][52] = {};
    queue<tuple<int, int, int>> q[2];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            tmp[i][j] = {b[i][j], 0};

    // 1 : g, 2 : r
    for (int i = 0; i < order.size(); i++) {
        if (order[i]) {
            int x, y;
            
            tie(x, y) = cand[i];
            q[order[i] - 1].push({x, y, 0});
            tmp[x][y] = {order[i] + 1, 0};
        }
    }

    int cur = 0;

    while (!q[0].empty() || !q[1].empty()) {
        while (!q[0].empty() && get<2>(q[0].front()) == cur) {
            int x, y, d;

            tie(x, y, d) = q[0].front(); q[0].pop();

            if (tmp[x][y].first == 1) continue;

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (tmp[nx][ny].first != 0) continue;

                tmp[nx][ny] = {2, d + 1};
                q[0].push({nx, ny, d + 1});
            }
        }

        while (!q[1].empty() && get<2>(q[1].front()) == cur) {
            int x, y, d;

            tie(x, y, d) = q[1].front(); q[1].pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (tmp[nx][ny].first == 1 || tmp[nx][ny].first == 3) continue;

                if (tmp[nx][ny].first == 2 && tmp[nx][ny].second == d + 1) {
                    tmp[nx][ny] = {1, 0};
                    cnt++;
                    continue;
                }
                tmp[nx][ny] = {3, d + 1};
                q[1].push({nx, ny, d + 1});
            }
        }

        cur++;
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> g >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a; cin >> a;

            if (a == 2) cand.push_back({i, j});
            else if (a == 0) b[i][j] = true;
        }
    }

    for (int i = cand.size() - 1; i >= 0; i--)
        order.push_back(i >= g + r ? 0 : (i >= r ? 1 : 2));

    do {
        ans = max(ans, solve(order));
    } while (next_permutation(order.begin(), order.end()));

    cout << ans;
}
