#include <iostream>

using namespace std;

long long arr[201][201], mod = 1000000000;


int main(void) {
    int n, k;

    cin >> n >> k;

    arr[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= j; k++) {
                arr[i][j] += arr[i-1][j-k] % mod; 
            }
        }
    }

    cout << arr[k][n] % mod;

    return 0;
}