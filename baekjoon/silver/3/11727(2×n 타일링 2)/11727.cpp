#include <iostream>

using namespace std;

int ans[1005] = {0, 1, 3};

int main(void) {
    int n;

    cin >> n;

    for (int i = 3; i <= n; i++) {
        ans[i] = (ans[i - 1] + 2 * ans[i - 2]) % 10007;
    }

    cout << ans[n];

    return 0;
}