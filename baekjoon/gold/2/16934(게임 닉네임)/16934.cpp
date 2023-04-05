#include <bits/stdc++.h>

using namespace std;

const int ROOT = 1;
const int MAX = 10 * 100000 + 5;
int unused = 2;
int nxt[MAX][26];
map<string, int> names;

int n;

int ctoi(char c) {
    return c - 'a';
}

void insert(string name) {
    int cur = ROOT;
    bool done = false;
    string nickname = "";

    for (char c : name) {
        if (!done) nickname += c;
        if (nxt[cur][ctoi(c)] == 0) {
            nxt[cur][ctoi(c)] = unused++;
            done = true;
        }

        cur = nxt[cur][ctoi(c)];
    }

    cout << nickname << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--) {
        string name; cin >> name;

        int cnt = ++names[name];
        if (cnt > 1) cout << name << cnt << '\n';
        else insert(name);
    }
}
