#include <iostream>
#include <algorithm>

using namespace std;

int arr[100005], max_sum[100005];

int main(void) {
    int n, ans = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        max_sum[i] = arr[i];
        if (i > 0 && max_sum[i-1] > 0)
            max_sum[i] += max_sum[i-1];
    }

    cout << *max_element(max_sum, max_sum + n);
}