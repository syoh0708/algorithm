#include <bits/stdc++.h>

using namespace std;

int arr[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x, sum, ans = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);

    cin >> x;

    int i = 0, j = n - 1;

    while (i < j) {
        sum = arr[i] + arr[j];
        if (sum == x) {
            ans++;
            i++;
        } else if (sum > x) {
            j--;
        } else {
            i++;
        }
    }

    cout << ans;
}
