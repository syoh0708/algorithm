#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000'000;
int n, m;
int board[105][105];
int dist[105][105];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
priority_queue<
    tuple<int, int, int>,
    vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>>
> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        fill(dist[i], dist[i] + m, MAX);
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    dist[0][0] = 0;
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        int d, x, y;

        tie(d, x, y) = pq.top(); pq.pop();
        if (d != dist[x][y]) continue;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[x][y] + board[nx][ny] < dist[nx][ny]) {
                dist[nx][ny] = dist[x][y] + board[nx][ny];
                pq.push({dist[nx][ny], nx, ny});
            }
        }
    }

    cout << dist[n - 1][m - 1];
}
