#include <bits/stdc++.h>

using namespace std;

int lc[27], rc[27];

void preorder(int cur) {
    cout << (char) ('A' + cur - 1);
    if (lc[cur]) preorder(lc[cur]);
    if (rc[cur]) preorder(rc[cur]);
}

void inorder(int cur) {
    if (lc[cur]) inorder(lc[cur]);
    cout << (char) ('A' + cur - 1);
    if (rc[cur]) inorder(rc[cur]);
}

void postorder(int cur) {
    if (lc[cur]) postorder(lc[cur]);
    if (rc[cur]) postorder(rc[cur]);
    cout << (char) ('A' + cur - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        char c, l, r; cin >> c >> l >> r;
        if (l != '.') lc[c - 'A' + 1] = l - 'A' + 1;
        if (r != '.') rc[c - 'A' + 1] = r - 'A' + 1;
    }

    preorder(1);
    cout << '\n';
    inorder(1);
    cout << '\n';
    postorder(1);
}
