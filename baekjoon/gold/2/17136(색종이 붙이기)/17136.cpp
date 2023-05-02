#include <bits/stdc++.h>

using namespace std;

int ans = 100;
bool b[15][15];
int cnt[6];

bool can_fill(int x, int y, int k) {
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            if (!b[x + i][y + j]) return false;

    return true;
}

void fill(int x, int y, int a, bool val) {
    for (int i = 0; i < a; i++)
        for (int j = 0; j < a; j++)
            b[x + i][y + j] = val;
}

void solve(int k) {
    while (k < 100 && !b[k / 10][k % 10]) k++;

    if (k == 100) {
        ans = min(ans, cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5]);

        return;
    }

    int x = k / 10, y = k % 10;

    for (int i = 1; i <= 5; i++) {
        if (!can_fill(x, y, i)) break;
        if (cnt[i] > 4) continue;
        cnt[i]++;
        fill(x, y, i, false);
        solve(k + 1);
        cnt[i]--;
        fill(x, y, i, true);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> b[i][j];

    solve(0);

    cout << (ans == 100 ? -1 : ans);
}
