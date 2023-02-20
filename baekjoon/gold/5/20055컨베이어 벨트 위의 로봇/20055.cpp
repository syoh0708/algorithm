#include <bits/stdc++.h>

using namespace std;

int durability[200];
bool robot[200];
int n, k, ans, on, off, broken;

int mod(int a, int b) {
    return (a % b + b) % b;
}

bool step() {
    on = mod(on - 1, 2 * n);
    off = mod(off - 1, 2 * n);

    if (robot[off]) robot[off] = false;
    for (int i = 0; i < n - 1; i++) {
        int cur = mod(off - i, 2 * n);
        int before = mod(cur - 1, 2 * n);
        if (robot[before] && !robot[cur] && durability[cur]) {
            if (cur != off) robot[cur] = true;

            robot[before] = false;
            durability[cur]--;

            if (!durability[cur]) broken++;
        }
    }
    
    if (durability[on]) {
        robot[on] = true;
        durability[on]--;

        if (!durability[on]) broken++;
    }

    ans++;

    return broken < k;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    on = 0; off = n - 1;

    for (int i = 0; i < 2 * n; i++) {
        cin >> durability[i];
    }

    while (step()) {}

    cout << ans;
}
