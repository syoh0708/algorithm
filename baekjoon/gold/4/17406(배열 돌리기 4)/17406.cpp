#include <bits/stdc++.h>

using namespace std;

int n, m, k, ans = 1'000'000;
int board[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int calc(int b[][51]) {
    int ans = 1'000'000;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) sum += b[i][j];
        ans = min(ans, sum);
    }

    return ans;
}

void rotate(int b[][51], int r, int c, int s) {
    for (int i = 1; i <= s; i++) {
        int px = r + i;
        int py = c + i;
        int last_val = b[px][py];
        int cx = px - 1;
        int cy = py;
        int dir = 0;

        while (cx != (r + i) || cy != (c + i)) {
            b[px][py] = b[cx][cy];
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx < r - i || nx > r + i || ny < c - i || ny > c + i) {
                dir++;
                nx = cx + dx[dir];
                ny = cy + dy[dir];
            }
            px = cx;
            py = cy;
            cx = nx;
            cy = ny;
        }
        b[cx][cy - 1] = last_val;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    vector<tuple<int, int, int>> ops;
    vector<int> order;

    for (int i = 0; i < k; i++) {
        int r, c, s; cin >> r >> c >> s;
        
        ops.push_back({r - 1, c - 1, s});
        order.push_back(i);
    }

    do {
        int tmp_board[51][51] = {};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) tmp_board[i][j] = board[i][j];
        }

        for (int o : order) {
            int r, c, s;
            tie(r, c, s) = ops[o];
            rotate(tmp_board, r, c, s);
        }        

        ans = min(ans, calc(tmp_board));
    } while (next_permutation(order.begin(), order.end()));
    
    cout << ans;
}
