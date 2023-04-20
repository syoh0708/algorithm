#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000'000;
int n, mx_depth = 1, mx_width;
int order;
int lc[10005];
int rc[10005];
int mn[10005];
int mx[10005];
vector<bool> is_root(10005, true);

void inorder(int cur, int depth) {
    if (lc[cur] > 0) inorder(lc[cur], depth + 1);
    mn[depth] = min(mn[depth], ++order);
    mx[depth] = max(mx[depth], order);
    if (rc[cur] > 0) inorder(rc[cur], depth + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int c, l, r; cin >> c >> l >> r;

        lc[c] = l;
        rc[c] = r;
        is_root[l] = false;
        is_root[r] = false;
    }

    int root = 1;
    for (int i = 1; i <= n; i++) {
        if (is_root[i]) {
            root = i;
            break;
        }
    }

    fill(mn + 1, mn + n + 2, MAX);
    inorder(root, 1);

    int d = 1;

    while (mn[d] != MAX) {
        if (mx[d] - mn[d] > mx_width) {
            mx_width = mx[d] - mn[d];
            mx_depth = d;
        }

        d++;
    }

    cout << mx_depth << ' ' << mx_width + 1;
}
