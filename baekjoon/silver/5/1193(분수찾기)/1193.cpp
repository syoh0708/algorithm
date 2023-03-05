#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k = 1; cin >> n;

    while (1) {
        if (n > (k * (k - 1) / 2) && n <= (k * (k + 1) / 2)) break;

        k++;
    }

    int c = k % 2 ? (k * (k + 1) / 2) + 1 - n : n - (k * (k - 1) / 2);
    int p = k % 2 ? n - (k * (k - 1) / 2) : (k * (k + 1) / 2) + 1 - n;

    cout << c << '/' << p;
}
