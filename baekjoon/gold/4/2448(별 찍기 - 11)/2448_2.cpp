#include <bits/stdc++.h>

using namespace std;

const int max_size = 3 * (1 << 10);

char triangle[max_size][2 * max_size];

void func(int n, int r, int c) {
    if (n == 3) {
        triangle[r][c + 2] = '*';
        triangle[r + 1][c + 1] = '*';
        triangle[r + 1][c + 3] = '*';
        fill(triangle[r + 2] + c, triangle[r + 2] + c + 5, '*');
        return;
    }

    func(n / 2, r, c + n / 2);
    func(n / 2, r + n / 2, c);
    func(n / 2, r + n / 2, c + n);

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        fill(triangle[i], triangle[i] + n * 2, ' ');
    }

    func(n, 0, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            cout << triangle[i][j];
        }
        cout << '\n';
    }
}
