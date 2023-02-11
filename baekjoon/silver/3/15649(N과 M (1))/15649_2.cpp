#include <bits/stdc++.h>

using namespace std;

int arr[9];
bool used[9];
int n, m;

void func(int c) {
    if (c == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            used[i] = true;
            arr[c] = i;
            func(c + 1);
            used[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func(0);
}
