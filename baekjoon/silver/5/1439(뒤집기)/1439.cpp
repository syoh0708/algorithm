#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s; cin >> s;

    int cnt = 1, sz = s.size();

    char c = s[0];

    for (int i = 1; i < sz; i++) {
        if (s[i] != c) {
            cnt++;
            c = s[i];
        }
    }

    cout << cnt / 2;
}
