#include <bits/stdc++.h>

using namespace std;

int arr[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, a;
    cin >> n;

    while (n--) {
        cin >> a;

        arr[a]++;
    }

    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < arr[i]; j++) {
            cout << i << '\n';
        }
    }
}
