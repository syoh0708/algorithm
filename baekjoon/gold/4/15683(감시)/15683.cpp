#include <bits/stdc++.h>

using namespace std;

int n, m, c, min_area = 100;
int board[9][9];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
vector<vector<vector<int>>> v = {
    {{}},
    {{0}, {1}, {2}, {3}}, 
    {{0, 2}, {1, 3}}, 
    {{0, 1}, {1, 2}, {2, 3}, {3, 0}}, 
    {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},
    {{0, 1, 2, 3}}
};
vector<tuple<int, int, int>> cctvs;

int get_area() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (!board[i][j]) ans++;
    }

    return ans;
}

void monitor(int r, int c, int dir, int fill) {
    while (1) {
        r += dx[dir];
        c += dy[dir];
        if (r < 0 || r >= n || c < 0 || c >= m || board[r][c] < 0) break;

        board[r][c] += fill;
    }
}

void func(int k) {
    if (k == c) {
        min_area = min(min_area, get_area());
        return;
    }

    int r, c, x;

    tie(r, c, x) = cctvs[k];

    for (vector<int> dirs : v[x]) {
        for (int dir : dirs) monitor(r, c, dir, 1);
        func(k + 1);
        for (int dir : dirs) monitor(r, c, dir, -1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a; cin >> a;
            board[i][j] = a;
            if (a > 0 && a < 6) cctvs.push_back({i, j, a});
            else if (a == 6) board[i][j] = -1;
        }
    }

    c = cctvs.size();

    func(0);

    cout << min_area;
}
