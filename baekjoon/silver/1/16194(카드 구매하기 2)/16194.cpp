#include <iostream>

using namespace std;

int arr[1001], ans[1001];

int main(void) {
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        ans[i] = arr[i];

        for (int j = 1; j <= i / 2; j++) {
            if (ans[i] > ans[j] + ans[i - j]) {
                ans[i] = ans[j] + ans[i - j];
            }
        }
    }

    cout << ans[n];

    return 0;
}