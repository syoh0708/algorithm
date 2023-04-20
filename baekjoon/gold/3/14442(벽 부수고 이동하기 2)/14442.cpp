#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000;
int n, m, k;
bool b[1005][1005];
pair<int, int> dist[1005][1005];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;

        for (int j = 0; j < m; j++)
            b[i][j] = (s[j] == '1');

        fill(dist[i], dist[i] + m, make_pair(MAX, MAX));
    }

    queue<tuple<int, int, int, int>> q;

    q.push({0, 0, 1, 0});
    dist[0][0] = {1, 0};

    while (!q.empty()) {
        int x, y, d, c;

        tie(x, y, d, c) = q.front(); q.pop();

        if (x == n - 1 && y == m - 1) {
            cout << d;
            return 0;
        }

        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nd = d + 1;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            int nc = c + b[nx][ny];
            
            if (nc > k || (nd >= dist[nx][ny].first && nc >= dist[nx][ny].second)) continue;

            dist[nx][ny] = {nd, nc};
            q.push({nx, ny, nd, nc});
        }
    }

    cout << -1;
}
