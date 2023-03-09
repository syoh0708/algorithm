#include <bits/stdc++.h>

using namespace std;

int arr[1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, ans = 0; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n, greater<int>());

    for (int i = 0; i < n; i++) {
        ans += (i + 1) * arr[i];
    }

    cout << ans;
}
