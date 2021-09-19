#include<iostream>
#include<algorithm>

using namespace std;

int cost[1001][3];
int min_cost[1001][3][3];

int main(void) {
    int n, ans = 1000000;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                min_cost[2][i][j] = 1000000;
            } else {
                min_cost[2][i][j] = cost[1][i] + cost[2][j];   
            }            
        }
    }

    for (int i = 3; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                min_cost[i][j][k] = min(min_cost[i - 1][j][(k + 1) % 3], min_cost[i - 1][j][(k + 2) % 3]) + cost[i][k];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;

            ans = min_cost[n][i][j] < ans ? min_cost[n][i][j] : ans;
        }
    }

    cout << ans << '\n';

    return 0;
}