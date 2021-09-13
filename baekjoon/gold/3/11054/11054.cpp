#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000], asc_max[1000], reverse_max[1000];

int main(void) {
    int n, ans = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        asc_max[i] = 1;
        reverse_max[n - 1 - i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && asc_max[i] < asc_max[j] + 1) {
                asc_max[i] = asc_max[j] + 1; 
            }

            if (arr[n - 1 - i] > arr[n - 1 - j] && reverse_max[n - 1 - i] < reverse_max[n - 1 - j] + 1) {
                reverse_max[n - 1 - i] = reverse_max[n - 1 - j] + 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (ans < asc_max[i] + reverse_max[i])
            ans = asc_max[i] + reverse_max[i];
    }

    cout << ans - 1;

    return 0;
}