#include <bits/stdc++.h>

using namespace std;

const int ROOT = 1;
const int MAX = 500 * 41 + 5;
int unused = 2;
vector<pair<string, int>> nxt[MAX];
int n;

void print_dirs(int cur, string prefix) {
    sort(nxt[cur].begin(), nxt[cur].end());

    for (auto sub : nxt[cur]) {
        cout << prefix << sub.first << '\n';
        print_dirs(sub.second, prefix + ' ');
    }
}

vector<string> split(string input, char delimeter) {
    vector<string> ret;
    string tmp;
    stringstream ss(input);

    while (getline(ss, tmp, delimeter)) {
        ret.push_back(tmp);
    }

    return ret;
}

void insert(vector<string> dirs) {
    int cur = ROOT;

    for (string dir : dirs) {
        int idx = -1;
        for (auto a : nxt[cur]) {
            if (a.first == dir) {
                idx = a.second;
                break;
            }
        }

        if (idx == -1) {
            idx = unused++;
            nxt[cur].push_back({dir, idx});
        }

        cur = idx;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--) {
        string s; cin >> s;

        vector<string> dirs = split(s, '\\');
        insert(dirs);
    }

    print_dirs(ROOT, "");
}
