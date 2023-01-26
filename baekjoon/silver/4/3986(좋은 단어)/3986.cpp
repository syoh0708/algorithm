#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, cnt = 0;

    cin >> n;

    while (n--) {
        string str;
        stack<char> s;

        cin >> str;

        for (char c : str) {
            if (s.empty() || s.top() != c) {
                s.push(c);
            } else {
                s.pop();
            }
        }

        if (s.empty()) cnt++;
    }

    cout << cnt;
}