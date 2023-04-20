#include <bits/stdc++.h>

using namespace std;

int n, m;
int b[505][505];
int cnt[505][505];
int inb[505][505];
vector<int> e[505][505];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cnt[0][0] = 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> b[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int dir = 0; dir < 4; dir++) {
                int ni = i + dx[dir];
                int nj = j + dy[dir];

                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if (b[i][j] > b[ni][nj]) {
                    e[i][j].push_back(dir);
                    inb[ni][nj]++;
                }
            }
        }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!inb[i][j]) q.push({i, j});
        }
    }

    while (!q.empty()) {
        int i, j;

        tie(i, j) = q.front(); q.pop();

        for (int dir : e[i][j]) {
            int ni = i + dx[dir];
            int nj = j + dy[dir];

            cnt[ni][nj] += cnt[i][j];

            if (!--inb[ni][nj]) q.push({ni, nj});
        }
    }
    
    cout << cnt[n - 1][m - 1];
}
