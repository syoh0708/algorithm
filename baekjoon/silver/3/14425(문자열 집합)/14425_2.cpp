#include <bits/stdc++.h>

using namespace std;

const int MAX = 500 * 10000 + 5;
const int ROOT = 1;
vector<pair<char, int>> nxt[MAX];
bool chk[MAX];
int unused = 2;
int n, m, ans;

int c2i(char c) {
    return c - 'a';
}

void insert(string& s) {
    int cur = ROOT;

    for (char c : s) {
        pair<char, int> x = {0, -1};
        for (auto y : nxt[cur]) {
            if (y.first == c) {
                x.first = y.first;
                x.second = y.second;
                break;
            }
        }
        if (x.first == 0) {
            x.first = c;
            x.second = unused++;
            nxt[cur].push_back(x);
        }

        cur = x.second;
    }

    chk[cur] = true;
}

bool find(string& s) {
    int cur = ROOT;

    for (char c : s) {
        pair<char, int> x = {0, -1};
        for (auto y : nxt[cur]) {
            if (y.first == c) {
                x.first = y.first;
                x.second = y.second;
                break;
            }
        }

        if (x.first == 0) return false;

        cur = x.second;
    }
        
    return chk[cur];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
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
