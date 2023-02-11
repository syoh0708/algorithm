#include <bits/stdc++.h>

using namespace std;

int order(int n, int r, int c) {
    if (n == 1) {
        return r * 2 + c;
    }

    int div = 1 << (n - 1);

    return div * div * (r / div * 2 + c / div) + order(n - 1, r % div, c % div);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r, c;

    cin >> n >> r >> c;

    cout << order(n, r, c);
}
