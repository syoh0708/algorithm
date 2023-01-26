#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;

    while (1) {
        getline(cin, str);

        if (str[0] == '.') break;

        stack<char> s;
        bool is_valid = true;

        for (char c : str) {
            if (c == '(' || c == '[') {
                s.push(c);
            } else if (c == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                } else {
                    is_valid = false;
                    break;
                }
            } else if (c == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                } else {
                    is_valid = false;
                    break;
                }
            }
        }

        if (!s.empty()) {
            is_valid = false;
        }

        if (is_valid) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}
