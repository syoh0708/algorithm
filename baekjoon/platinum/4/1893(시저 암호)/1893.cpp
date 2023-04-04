#include <bits/stdc++.h>

using namespace std;

string encode(string& voca, string& word, int sh) {
    string ret = "";
    vector<char> i2c;
    unordered_map<char, int> c2i;
    int sz = voca.size();

    for (int i = 0; i < sz; i++) {
        i2c.push_back(voca[i]);
        c2i[voca[i]] = i;
    }

    for (char c : word) ret += i2c[(c2i[c] + sh) % sz];

    return ret;
}

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

bool contains_one(string& a, string& b) {
    int cnt = 0, alen = a.size(), blen = b.size();
    vector<int> f = failure(b);

    int j = 0;
    for (int i = 0; i < alen; i++) {
        while (j > 0 && a[i] != b[j]) j = f[j - 1];
        if (a[i] == b[j]) j++;
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
        string A, W, S; cin >> A >> W >> S;

        vector<string> words = {W};
        vector<int> ans;

        int alen = A.size();
        for (int i = 1; i < alen; i++) words.push_back(encode(A, W, i));
        for (int i = 0; i < words.size(); i++)
            if (contains_one(S, words[i])) ans.push_back(i);
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
