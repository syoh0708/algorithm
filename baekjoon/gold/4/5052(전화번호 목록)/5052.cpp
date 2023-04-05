#include <bits/stdc++.h>

using namespace std;

const int ROOT = 1;
const int MAX = 10000 * 10 + 5;
int unused = 2;
int nxt[MAX][10];
bool chk[MAX];

int c2i(char c) {
    return c - '0';
}

bool insert(string& s) {
    int cur = ROOT;

    for (char c : s) {
        if (nxt[cur][c2i(c)] == -1) nxt[cur][c2i(c)] = unused++;

        cur = nxt[cur][c2i(c)];
        if (chk[cur]) return false;
    }

    for (int i = 0; i < 10; i++) {
        if (nxt[cur][i] != -1) return false;
    }
    return chk[cur] = true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) {
        unused = 2;
        for (int i = 0; i < MAX; i++) fill(nxt[i], nxt[i] + 10, -1);
        fill(chk, chk + MAX, false);

        int n; cin >> n;
        bool good = true;
        while (n--) {
            string s; cin >> s;

            if (!insert(s)) {
                good = false;
            }
        }

        cout << (good ? "YES\n" : "NO\n");
    }
}
