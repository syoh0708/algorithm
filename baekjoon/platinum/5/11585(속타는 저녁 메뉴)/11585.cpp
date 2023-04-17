#include <bits/stdc++.h>

using namespace std;

int n, cnt;

vector<int> failure(string& s) {
    int sz = s.size();
    vector<int> f(sz);

    int j = 0;

    for (int i = 1; i < n; i++) {
        while (j && s[i] != s[j]) j = f[j - 1];
        if (s[i] == s[j]) f[i] = ++j;
    }

    return f;
}

int count(string& a, string& b) {
    int alen = a.size(), blen = b.size(), cnt = 0;
    vector<int> f = failure(b);

    int j = 0;

    for (int i = 0; i < alen - 1; i++) {
        while (j && a[i] != b[j]) j = f[j - 1];
        if (a[i] == b[j]) j++;

        if (j == blen) cnt++;
    }

    return cnt;
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    string ans = "", text = "";

    for (int i = 0; i < n; i++) {
        char c; cin >> c;

        ans += c;
    }

    for (int i = 0; i < n; i++) {
        char c; cin >> c;

        text += c;
    }

    text += text;
    
    int cnt = count(text, ans);
    int g = gcd(cnt, n);

    cout << cnt / g << '/' << n / g;
}
