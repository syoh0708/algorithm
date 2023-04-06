#include <bits/stdc++.h>

using namespace std;

int n;
int d[250005];
long long ans;
set<int> s;
vector<bool> lc(250005);
vector<bool> rc(250005);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int a; cin >> a;

    d[a] = 1;
    ans += d[a];
    s.insert(a);    

    for (int i = 1; i < n; i++) {
        cin >> a;

        auto tmp = s.lower_bound(a);
        int val = *tmp;
        if (tmp == s.end() || lc[val]) {
            tmp = prev(tmp);
            val = *tmp;
            rc[val] = true;
        } else {
            lc[val] = true;
        }

        s.insert(a);
        d[a] = d[val] + 1;
        ans += d[a];
    }

    cout << ans;
}
