#include <bits/stdc++.h>

using namespace std;

int n, ans;
int ing[10][16][5][5];
char col[10][16][5][5];


int solve(vector<int>& order, int rotate) {
    int val = 0;
    int b[5][5] = {};
    char c[5][5] = {};
    int real_order[3] = {};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < order.size(); j++) {
            if (order[j] == i + 1) real_order[i] = j;
        }
    }

    for (int k = 0; k < 3; k++) {
        int cur = real_order[k];
        int cur_rot = rotate % 16;
        rotate /= 16;
        
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                b[i][j] += ing[cur][cur_rot][i][j];
                if (b[i][j] < 0) b[i][j] = 0;
                if (b[i][j] > 9) b[i][j] = 9;
                if (col[cur][cur_rot][i][j] != 'W' && col[cur][cur_rot][i][j] != '\0') c[i][j] = col[cur][cur_rot][i][j];
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int d = 0;
            // 7R + 5B + 3G + 2Y
            if (c[i][j] == 'R') d = 7;
            else if (c[i][j] == 'B') d = 5;
            else if (c[i][j] == 'G') d = 3;
            else if (c[i][j] == 'Y') d = 2;

            val += d * b[i][j];
        }
    }

    return val;
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int a; cin >> a;
                ing[k][0][i][j] = a;
                ing[k][1][j][3 - i] = a;
                ing[k][2][3 - i][3 - j] = a;
                ing[k][3][3 - j][i] = a;
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                char c; cin >> c;
                col[k][0][i][j] = c;
                col[k][1][j][3 - i] = c;
                col[k][2][3 - i][3 - j] = c;
                col[k][3][3 - j][i] = c;
            }
        }

        for (int x = 0; x < 4; x++) {
            for (int y = 1; y < 4; y++) {
                int di = y % 2, dj = y / 2;
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 4; j++) {
                        ing[k][x + 4 * y][i + di][j + dj] = ing[k][x][i][j];
                        col[k][x + 4 * y][i + di][j + dj] = col[k][x][i][j];
                    }
                }
            }
        }
    }

    vector<int> order;

    for (int i = 0; i < n; i++) {
        if (i < n - 3) order.push_back(0);
        else order.push_back(i - n + 4);
    }

   do {
        for (int i = 0; i < (1 << 10); i++) {
            ans = max(ans, solve(order, i));            
        }
    } while (next_permutation(order.begin(), order.end()));

    cout << ans;
}
