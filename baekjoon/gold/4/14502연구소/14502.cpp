#include <bits/stdc++.h>

using namespace std;

int board[8][8];
bool used[64];
int order[3];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> v;
int n, m;
int max_safe_area;

int get_safe_area() {
    int tmp_board[8][8];
    bool vis[8][8] = {};
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tmp_board[i][j] = board[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        tmp_board[order[i] / m][order[i] % m] = 1;
    }

    for (auto p : v) {
        q.push(p);
        vis[p.first][p.second] = true;
    }

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (tmp_board[nx][ny] != 0 || vis[nx][ny]) continue;

            tmp_board[nx][ny] = 2;
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    int safe_area = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!tmp_board[i][j]) safe_area++;
        }
    }

    return safe_area;
}

void func(int k) {
    if (k == 3) {
        max_safe_area = max(max_safe_area, get_safe_area());
        return;
    }

    for (int i = 0; i < n * m; i++) {
        if (used[i] || board[i / m][i % m] != 0) continue;

        used[i] = true;
        order[k] = i;
        func(k + 1);
        used[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) v.push_back({i, j});
        }
    }

    vector<bool> order(n * m - 3, false);
    for (int i = 0; i < 3; i++) {
        order.push_back(true);
    }

    func(0);

    cout << max_safe_area;
}
