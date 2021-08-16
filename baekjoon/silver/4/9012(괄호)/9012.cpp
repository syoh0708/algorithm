#include<iostream>
#include<stack>
#include<string>

using namespace std;

string is_valid(string str) {
    stack<char> s;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
                s.push('(');
            } else {
                if (s.empty()) {
                    return "NO";
                }

                s.pop();
            }
    }

    if (s.empty()) {
        return "YES";
    } else {
        return "NO";
    }

}

int main(void) {
    int n;

    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        cout << is_valid(s) << '\n';
    }

    return 0;
}