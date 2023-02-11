#include <bits/stdc++.h>

using namespace std;

int board[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, max_safe_area = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int h = 0; h <= 100; h++) {
        int safe_area = 0;
        queue<pair<int, int>> q;
        bool vis[100][100] = {};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] <= h || vis[i][j]) continue;

                safe_area++;
                q.push({i, j});
                vis[i][j] = true;

                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (board[nx][ny] <= h || vis[nx][ny]) continue;
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }   
                }
            }
        }

        max_safe_area = max(max_safe_area, safe_area);
    }
    
    cout << max_safe_area;
}
