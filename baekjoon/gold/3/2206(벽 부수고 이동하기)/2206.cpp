#include <bits/stdc++.h>

using namespace std;

bool board[1000][1000];
pair<int, int> dist[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    queue<pair<int, int>> q;
    int n, m; 
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        fill(dist[i], dist[i] + m, make_pair(-1, -1));
    }

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = (s[j] - '1');
        }
    }

    dist[0][0] = {1, -1};
    q.push({0, 0});

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        int cx = cur.first;
        int cy = cur.second;

        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            bool updated = false;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[cx][cy]) {
                if (board[nx][ny]) {
                    if (dist[cx][cy].first >= 0 && (dist[nx][ny].first == -1 || dist[cx][cy].first + 1 < dist[nx][ny].first)) {
                        dist[nx][ny].first = dist[cx][cy].first + 1;
                        updated = true;
                    }
                    if (dist[cx][cy].second >= 0 && (dist[nx][ny].second == -1 || dist[cx][cy].second + 1 < dist[nx][ny].second)) {
                        dist[nx][ny].second = dist[cx][cy].second + 1;
                        updated = true;
                    }
                } else {
                    if (dist[cx][cy].first >= 0 && (dist[nx][ny].second == -1 || dist[cx][cy].first + 1 < dist[nx][ny].second)) {
                        dist[nx][ny].second = dist[cx][cy].first + 1;
                        updated = true;
                    }
                }
            } else {
                if (board[nx][ny] && (dist[nx][ny].second == -1 || dist[cx][cy].second + 1 < dist[nx][ny].second)) {
                    dist[nx][ny].second = dist[cx][cy].second + 1;
                    updated = true;
                }
            }

            if (updated) {
                q.push({nx, ny});
            }
        }
    }

    if (dist[n - 1][m - 1].first == -1) {
        cout << dist[n - 1][m - 1].second;
    } else if (dist[n - 1][m - 1].second == -1) {
        cout << dist[n - 1][m - 1].first;
    } else {
        cout << min(dist[n - 1][m - 1].first, dist[n - 1][m - 1].second);
    }
}
