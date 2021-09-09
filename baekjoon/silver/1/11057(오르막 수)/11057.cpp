#include <iostream>

using namespace std;

int mod = 10007;
int arr[1001][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int main(void) {

    int n, ans = 0;

    cin >> n;

    for (int i = 2; i <= n; i++) {
        arr[i][0] = arr[i - 1][0];

        for (int j = 1; j < 10; j++) {
            arr[i][j] = (arr[i][j - 1] + arr[i - 1][j]) % mod;
        }
    }

    for (int i = 0; i < 10; i++) {
        ans += arr[n][i];
    }

    cout << ans % mod;

    return 0;
}