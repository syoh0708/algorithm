#include <bits/stdc++.h>

using namespace std;

int n, m;
unordered_map<string, int> um;
string a[1005];
int indg[1005];
int outdg[1005];
vector<int> e[1005];
vector<int> anc;
vector<int> ch[1005];
queue<int> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++) um[a[i]] = i;

    cin >> m;
    
    while (m--) {
        string child, ancestor; cin >> child >> ancestor;

        indg[um[child]]++;
        outdg[um[ancestor]]++;
        e[um[ancestor]].push_back(um[child]);
    }

    for (int i = 0; i < n; i++) {
        if (!indg[i]) {
            anc.push_back(i);
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int nxt : e[cur]) {
            indg[nxt]--;

            if (!indg[nxt]) {
                q.push(nxt);
                ch[cur].push_back(nxt);
            }
        }
    }

    cout << anc.size() << '\n';
    for (int k : anc) cout << a[k] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ' << ch[i].size() << ' ';
        sort(ch[i].begin(), ch[i].end());
        for (int j : ch[i]) cout << a[j] << ' ';
        cout << '\n';
    }
}
