#include <bits/stdc++.h>

using namespace std;

int n, m, k, ans, cx, cy, dir;
int board[22][22];
int score[22][22];
int vis[22][22];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dice[6] = {6, 5, 1, 2, 4, 3}; // 하, 전, 상, 후, 좌, 우;
int tmp[6];
int rot[4][6] = {
    {5, 1, 4, 3, 0, 2},
    {1, 2, 3, 0, 4, 5},
    {4, 1, 5, 3, 2, 0},
    {3, 0, 1, 2, 4, 5}
};

void roll() {
    int nx = cx + dx[dir], ny = cy + dy[dir];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) dir = (dir + 2) % 4;
    cx = cx + dx[dir];
    cy = cy + dy[dir];


    ans += score[cx][cy];

    for (int i = 0; i < 6; i++) tmp[i] = dice[rot[dir][i]];
    for (int i = 0; i < 6; i++) dice[i] = tmp[i];

    int a = dice[0], b = board[cx][cy];
    
    if (a > b) dir = (dir + 1) % 4;
    if (a < b) dir = (dir + 3) % 4;
}

void fill_score() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == 1) continue;

            int pt = board[i][j], sum = 0;
            queue<pair<int, int>> q;

            vis[i][j] = 2;
            q.push({i, j});
            
            while (!q.empty()) {
                int x, y;
                tie(x, y) = q.front(); q.pop();
                sum += pt;

                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || board[nx][ny] != pt) continue;

                    vis[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }

            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if (vis[x][y] != 2) continue;

                    vis[x][y] = 1;
                    score[x][y] = sum;
                }    
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    fill_score();

    while (k--) roll();

    cout << ans;
}
