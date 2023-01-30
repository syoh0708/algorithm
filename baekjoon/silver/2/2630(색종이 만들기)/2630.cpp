#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

bool arr[257][257];

pair<int, int> func(int r, int c, int n) {
    bool same_color = true;

    for (int i = r; i < r + n; i++) {
        for (int j = c; j < c + n; j++)
        {
            if (arr[r][c] != arr[i][j]) {
                same_color = false;
                break;
            }
        }
    }

    if (same_color) {
        return arr[r][c] ? make_pair(0, 1) : make_pair(1, 0);
    } else {
        pair<int, int> p0, p1, p2, p3;
        p0 = func(r, c, n / 2);
        p1 = func(r + n / 2, c, n / 2);
        p2 = func(r, c + n / 2, n / 2);
        p3 = func(r + n / 2, c + n / 2, n / 2);

        return {p0.X + p1.X + p2.X + p3.X, p0.Y + p1.Y + p2.Y + p3.Y};
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    pair<int, int> ret = func(0, 0, n);

    cout << ret.X << '\n' << ret.Y;
}
