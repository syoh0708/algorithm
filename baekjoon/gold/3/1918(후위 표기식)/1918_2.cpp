#include <iostream>
#include <stack>
#include <string>

using namespace std;

int get_priority(char c) {
    if (c == '(') {
        return 2;
    } else if (c == '*' || c == '/') {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {
    string infix;
    string ans;
    char op;

    cin >> infix;

    stack<string> operands;
    stack<char> ops;
    int additional_priority = 0;

    for (char c : infix) {
        if ('A' <= c && c <= 'Z') {
            ans += c;
        } else if (c == '(') {
            ops.push(c);
        } else if (c == ')') {
            while (ops.top() != '(' && get_priority(ops.top()) >= get_priority(c)) {
                ans += ops.top();
                ops.pop();
            }

            ops.pop();
        } else {
            while (!ops.empty() && ops.top() != '(' && get_priority(ops.top()) >= get_priority(c)) {
                ans += ops.top();
                ops.pop();
            }

            ops.push(c);
        }
    }

    while (!ops.empty()) {
        ans += ops.top();
        ops.pop();
    }

    cout << ans;

    return 0;
}
