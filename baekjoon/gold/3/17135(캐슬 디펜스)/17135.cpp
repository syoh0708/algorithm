#include <bits/stdc++.h>

using namespace std;

int n, m, d, ans;
int board[17][17];

void kill(vector<vector<int>>& tmp_board, int archer) {
    int nn = tmp_board.size();
    for (int dist = 1; dist <= d; dist++) {
        for (int dj = -dist + 1; dj < dist; dj++) {
            int di = dist - abs(dj);

            int i = nn - di, j = archer + dj;
            if (i < 0 || i >= nn || j < 0 || j >= m) continue;
            if (tmp_board[i][j]) {
                tmp_board[i][j]++;
                return;
            }
        }
    }
}

int solve(vector<bool>& order) {
    int ans = 0;
    vector<vector<int>> tmp_board(n);
    vector<int> archers;

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            tmp_board[i].push_back(board[i][j]);

    for (int i = 0; i < m; i++) if (order[i]) archers.push_back(i);
    for (int i = 0; i < n; i++) {
        for (int archer : archers) kill(tmp_board, archer);
        for (int ii = 0; ii < tmp_board.size(); ii++) {
            for (int jj = 0; jj < m; jj++) {
                if (tmp_board[ii][jj] > 1) {
                    ans++;
                    tmp_board[ii][jj] = 0;
                }
            }
        }

        tmp_board.pop_back();
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    vector<bool> order;
    for (int i = 0; i < m; i++) order.push_back((i < m - 3 ? 0 : 1));

    do {
        ans = max(ans, solve(order));
    } while (next_permutation(order.begin(), order.end()));

    cout << ans;
}
