#include <bits/stdc++.h>

using namespace std;

int origin[257], shift[257];
string A, W, S;

vector<int> failure(string& s) {
    int len = s.size();
    vector<int> v(len);

    int j = 0;
    for (int i = 1; i < len; i++) {
        while (j > 0 && s[i] != s[j]) j = v[j - 1];
        if (s[i] == s[j]) v[i] = ++j;
    }

    return v;
}

bool contains_one(string& a, string& b, int sh) {
    for (char c : A) shift[c] = (origin[c] + sh) % A.size();
    
    int cnt = 0, alen = a.size(), blen = b.size();
    vector<int> f = failure(b);

    int j = 0;
    for (int i = 0; i < alen; i++) {
        while (j > 0 && origin[a[i]] != shift[b[j]]) j = f[j - 1];
        if (origin[a[i]] == shift[b[j]]) j++;
        if (j == blen) cnt++;
        if (cnt > 1) break;
    }

    return cnt == 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) {
        cin >> A >> W >> S;

        vector<int> ans;

        int alen = A.size();
        for (int i = 0; i < alen; i++) origin[A[i]] = i;
        for (int i = 0; i < alen; i++)
            if (contains_one(S, W, i)) ans.push_back(i);

        int ans_cnt = ans.size();
        if (ans_cnt == 0) cout << "no solution\n";
        else if (ans_cnt == 1) cout << "unique: " << ans[0] << '\n';
        else {
            cout << "ambiguous: ";
            for (int a : ans) cout << a << ' ';
            cout << '\n';
        }
    }
}
