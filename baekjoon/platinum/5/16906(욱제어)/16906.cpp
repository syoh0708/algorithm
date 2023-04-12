#include <bits/stdc++.h>

using namespace std;

const int ROOT = 1;
const int MAX = 1000 * 1000 + 5;
int unused = 2;
int nxt[MAX][2];
int par[MAX];
bool chk[MAX];
int n;
pair<int, int> a[1005];
string ans[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    
    stable_sort(a, a + n);

    bool impossible = false;

    for (int i = 0; i < n; i++) {
        int len = a[i].first;
        int cur = ROOT;
        string word = "";

        for (int j = 0; j < len; j++) {
            if (chk[cur]) {
                impossible = true;
                break;
            }

            if (chk[nxt[cur][0]]) {
                if (!nxt[cur][1]) {
                    nxt[cur][1] = unused++;
                    par[nxt[cur][1]] = cur;
                }
                
                word += '1';
                cur = nxt[cur][1];
            } else {
                if (!nxt[cur][0]) {
                    nxt[cur][0] = unused++;
                    par[nxt[cur][0]] = cur;
                }
                word += '0';
                cur = nxt[cur][0];
            }
        }

        chk[cur] = true;
        while (cur && chk[nxt[par[cur]][1]]) {
            chk[par[cur]] = true;
            cur = par[cur];
        }
        ans[a[i].second] = word;

        if (impossible) break;
    }

    if (impossible) cout << -1;
    else  {
        cout << 1 << '\n';
        for (int i = 0; i < n; i++) {
            cout << ans[i] << '\n';
        }
    }
}
