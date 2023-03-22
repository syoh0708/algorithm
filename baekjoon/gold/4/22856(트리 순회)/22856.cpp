#include <bits/stdc++.h>

using namespace std;

int lc[100005];
int rc[100005];
int par[100005];
bool vis[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cnt = 0; cin >> n;

    while (n--) {
        int c, l, r; cin >> c >> l >> r;

        if (l != -1) {
            lc[c] = l;
            par[l] = c;
        }
        if (r != -1) {
            rc[c] = r;
            par[r] = c;
        }
    }

    int last = 1, cur = 1;
    while (rc[last]) last = rc[last];

    while (1) {
        if (lc[cur] && !vis[lc[cur]]) cur = lc[cur];
        else if (rc[cur] && !vis[rc[cur]]) cur = rc[cur];
        else if (cur == last) break;
        else cur = par[cur];

        vis[cur] = true;
        cnt++;
    }

    cout << cnt;
}
