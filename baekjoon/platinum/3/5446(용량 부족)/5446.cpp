#include <bits/stdc++.h>

using namespace std;

const int ROOT = 1;
const int DELETED = 1;
const int MARKED = 2;
const int MAX = 20 * 1000 + 5;
int unused = 2;
int t, n, m;
string del[1005];
int nxt[MAX][256];
int chk[MAX];

void insert(string& s) {
    int cur = ROOT;

    for (char c : s) {
        if (!nxt[cur][c]) nxt[cur][c] = unused++;

        cur = nxt[cur][c];
    }
}

void mark(string& s) {
    int cur = ROOT;
    
    chk[cur] = MARKED;

    for (char c : s) {
        if (!nxt[cur][c]) break;

        chk[nxt[cur][c]] = MARKED;
        cur = nxt[cur][c];
    }
}

bool erase(string& s) {
    int cur = ROOT;

    if (chk[cur] != MARKED) {
        if (chk[cur] != DELETED) {
            chk[cur] = DELETED;
            return true;
        }

        return false;
    }

    for (char c : s) {
        cur = nxt[cur][c];

        if (chk[cur] != MARKED) {
            if (chk[cur] != DELETED) {
                chk[cur] = DELETED;
                return true;
            }

            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--) {
        int ans = 0;
        
        unused = 2;
        memset(nxt, 0, sizeof(nxt));
        memset(chk, 0, sizeof(chk));

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> del[i];
            insert(del[i]);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            string s; cin >> s;
            mark(s);
        }

        for (int i = 0; i < n; i++) {
            ans += erase(del[i]);
        }

        cout << ans << '\n';
    }
}
