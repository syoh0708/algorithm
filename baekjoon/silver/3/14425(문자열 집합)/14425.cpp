#include <bits/stdc++.h>

using namespace std;

const int MAX = 500 * 10000 + 5;
const int ROOT = 1;
int nxt[MAX][26];
bool chk[MAX];
int unused = 2;
int n, m, ans;

int c2i(char c) {
    return c - 'a';
}

void insert(string& s) {
    int cur = ROOT;

    for (char c : s) {
        if (nxt[cur][c2i(c)] == -1) nxt[cur][c2i(c)] = unused++;
        cur = nxt[cur][c2i(c)];
    }

    chk[cur] = true;
}

bool find(string& s) {
    int cur = ROOT;

    for (char c : s) {
        if (nxt[cur][c2i(c)] == -1) return false;
        cur = nxt[cur][c2i(c)];
    }
        
    return chk[cur];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < MAX; i++) fill(nxt[i], nxt[i] + 26, -1);
    
    while (n--) {
        string s; cin >> s;

        insert(s);
    }

    while (m--) {
        string s; cin >> s;

        ans += find(s);
    }

    cout << ans;
}
