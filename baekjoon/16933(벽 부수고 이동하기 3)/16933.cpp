#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000'000;
int n, m, k;
bool board[1005][1005];
pair<int, int> dist[1005][1005];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;

        for (int j = 0; j < m; j++) {
            if (s[j] == '1') board[i][j] = true;
        }
        fill(dist[i], dist[i] + m, make_pair(MAX, MAX));
    }

    dist[0][0] = {1, 0};
    queue<tuple<int, int, int, int>> q[2];

    int dcur = 1;
    q[1].push({0, 0, 1, 0});

    while (!q[0].empty() || !q[1].empty()) {
        if (q[dcur % 2].empty()) {
            dcur++;
            continue;
        }

        int x, y, d, c;

        tie(x, y, d, c) = q[dcur % 2].front();

        if (d > dcur) {
            dcur++;
            continue;
        }

        if (x == n - 1 && y == m - 1) {
            cout << d;
            return 0;
        }
        
        q[d % 2].pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            int nd = d + 1;
            int nc = c;
            if (board[nx][ny]) {
                nc++;
                if (nd % 2) nd++;
            }

            if (nc > k) continue;
            if (nd >= dist[nx][ny].first && nc >= dist[nx][ny].second) continue;

            dist[nx][ny] = {nd, nc};
            q[nd % 2].push({nx, ny, nd, nc});
        }   
    }

    cout << -1;
}
