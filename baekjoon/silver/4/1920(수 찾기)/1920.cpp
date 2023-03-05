#include <bits/stdc++.h>

using namespace std;

int arr[100000];

bool is_in(int st, int end, int n) {
    if (end - st == 1) return arr[st] == n;

    int mid = (st + end) / 2;

    if (arr[mid] == n) {
        return true;
    } else if (arr[mid] > n) {
        return is_in(st, mid, n);
    } else {
        return is_in(mid, end, n);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    cin >> m;

    while (m--) {
        int query;

        cin >> query;

        cout << is_in(0, n, query) << '\n';
    }
}
