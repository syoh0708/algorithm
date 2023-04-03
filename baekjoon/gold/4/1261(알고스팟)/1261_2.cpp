#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000'000;
int n, m;
string board[105];
int dist[105][105];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
deque<pair<int, int>> dq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        cin >> board[i];
        fill(dist[i], dist[i] + m, MAX);
    }

    dq.push_back({0, 0});
    dist[0][0] = 0;

    while (!dq.empty()) {
        int cx, cy, cw;
        tie(cx, cy) = dq.front(); dq.pop_front();
        cw = dist[cx][cy];

        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            int nw = cw + (board[nx][ny] - '0');

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (nw < dist[nx][ny]) {
                dist[nx][ny] = nw;
                if (cw == nw) dq.push_front({nx, ny});
                else dq.push_back({nx, ny});
            }
        }   
    }

    cout << dist[n - 1][m - 1];
}
