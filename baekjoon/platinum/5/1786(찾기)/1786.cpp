#include <bits/stdc++.h>

using namespace std;

vector<int> failure(string &s) {
    int len = s.size();
    vector<int> v(len);

    int j = 0;
    for (int i = 1; i < len; i++) {
        while (j > 0 && s[i] != s[j]) j = v[j - 1];
        if (s[i] == s[j]) v[i] = ++j;
    }

    return v;
}

vector<int> contains(string& a, string& b) {
    vector<int> v;
    vector<int> f = failure(b);

    int j = 0, alen = a.size(), blen = b.size();
    for (int i = 0; i < alen; i++) {
        while (j > 0 && a[i] != b[j]) j = f[j - 1];
        if (a[i] == b[j]) j++;
        if (j == blen) v.push_back(i - j + 2);
    }

    return v;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string t, p;
    getline(cin, t);
    getline(cin, p);

    vector<int> ans = contains(t, p);
    cout << ans.size() << '\n';
    for (int a : ans) cout << a << ' ';
}
