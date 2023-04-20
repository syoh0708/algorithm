#include <bits/stdc++.h>

using namespace std;

int n, m, k, ans;
int a[11][11];
int board[11][11];
int reprod[11][11];
deque<int> tree[11][11];
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }

        fill(board[i], board[i] + n, 5);
    }

    while (m--) {
        int x, y, z; cin >> x >> y >> z;

        tree[x - 1][y - 1].push_back(z);
    }

    while (k--) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = tree[i][j].size();
                int fert = board[i][j];
                int used = 0;

                while (cnt--) {
                    int age = tree[i][j].front(); tree[i][j].pop_front();
                    if (used + age <= fert) {
                        used += age;
                        tree[i][j].push_back(age + 1);
                        if ((age + 1) % 5 == 0) reprod[i][j]++;
                    } else {
                        board[i][j] += age / 2;
                    }
                }

                board[i][j] -= used;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = reprod[i][j];

                if (!cnt) continue;

                for (int dir = 0; dir < 8; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    
                    for (int k = 0; k < cnt; k++) {
                        tree[nx][ny].push_front(1);                        
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] += a[i][j];
            }

            fill(reprod[i], reprod[i] + n , 0);
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans += tree[i][j].size();

    cout << ans;
}
