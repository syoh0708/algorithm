#include <bits/stdc++.h>

using namespace std;

int arr[500000];

int ub(int k, int len) {
    int st = 0, end = len;

    while (st < end) {
        int mid = (st + end) / 2;

        if (arr[mid] <= k) {
            st = mid + 1;
        } else {
            end = mid;
        }
    }

    return st;
}

int lb(int k, int len) {
    int st = 0, end = len;

    while (st < end) {
        int mid = (st + end) / 2;

        if (arr[mid] < k) {
            st = mid + 1;
        } else {
            end = mid;
        }
    }

    return st;
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

        cout << ub(query, n) - lb(query, n) << ' ';
    }
}
