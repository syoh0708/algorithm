#include <iostream>

using namespace std;

long long stairs[101][10] {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int main(void) {
    int n;

    for (int i = 2; i <= 100; i++) {
        for (int j = 0; j < 10; j++) {
            if (j > 0) {
                stairs[i][j] += stairs[i-1][j-1] % 1000000000;
            }

            if (j < 9) {
                stairs[i][j] += stairs[i-1][j+1] % 1000000000;
            }
        }

    }

    cin >> n;

    long long ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += stairs[n][i];
    }

    cout << ans % 1000000000;

    return 0;
}