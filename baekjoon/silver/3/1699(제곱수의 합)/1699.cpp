#include <iostream>

using namespace std;

int ans[100005];

int main(void) {
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        ans[i] = i;

        for (int j = 1; j * j <= i; j++) {
            if (ans[i] > ans[i - j * j] + 1) {
                ans[i] = ans[i - j * j] + 1;
            }
        }
    }

    cout << ans[n];
}