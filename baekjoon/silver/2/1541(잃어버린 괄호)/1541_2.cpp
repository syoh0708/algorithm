#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s; cin >> s;

    int ans = 0, tmp = 0, sign = 1;

    for (char c : s) {
        if (isdigit(c)) {
            tmp *= 10;
            tmp += (c - '0');
        } else {
            ans += sign * tmp;
            tmp = 0;

            if (c == '-') sign = -1;
        }
    }

    ans += sign * tmp;

    cout << ans;
}
