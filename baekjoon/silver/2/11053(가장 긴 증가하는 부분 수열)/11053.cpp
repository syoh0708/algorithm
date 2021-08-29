#include <iostream>

using namespace std;


int main(void) {
    int n, ans = 0, arr[1000], longest_array_ends_at[1000];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        longest_array_ends_at[i] = 1;

        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && longest_array_ends_at[j] >= longest_array_ends_at[i]) {
                longest_array_ends_at[i] = longest_array_ends_at[j] + 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ans = longest_array_ends_at[i] > ans ? longest_array_ends_at[i] : ans;
    }

    cout << ans;
}