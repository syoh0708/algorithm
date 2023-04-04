#include <bits/stdc++.h>

using namespace std;

vector<int> failure(string& s) {
    int sz = s.size();
    vector<int> v(sz);

    int j = 0;
    for (int i = 1; i < sz; i++) {
        while (j > 0 && s[i] != s[j]) j = v[j - 1];
        if (s[i] == s[j]) v[i] = ++j;
    }

    return v;
}

bool contains(string& a, string& b) {
    vector<int> f = failure(b);


    int j = 0, sz = a.size();
    for (int i = 0; i < sz; i++) {
        while (j > 0 && a[i] != b[j]) j = f[j - 1];
        if (a[i] == b[j]) j++;
        if (j == b.size()) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, k; cin >> s >> k;

    string str = "";

    for (char c : s) {
        if (!isdigit(c)) str += c;
    }
    
    cout << contains(str, k);
}
