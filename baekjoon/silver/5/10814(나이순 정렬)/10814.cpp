#include <bits/stdc++.h>

using namespace std;

pair<int, string> arr[100000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, a;
    string name;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    stable_sort(arr, arr + n, [](pair<int, string> a, pair<int, string> b) {
        return a.first < b.first;
    });

    for (int i = 0; i < n; i++) {
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }
}
