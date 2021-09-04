#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
    string infix;
    char op;

    cin >> infix;

    stack<string> operands;
    stack<pair<char, int>> ops;
    int additional_priority = 0;

    for (char c : infix) {
        if ('A' <= c && c <= 'Z') {
            operands.push(string(1, c));
        } else if (c == '(') {
            additional_priority += 2;
        } else if (c == ')') {
            additional_priority -= 2;
        } else {
            int priority = additional_priority + ((c == '*' || c == '/') ? 1 : 0);

            while (!ops.empty() && ops.top().second >= priority) {
                string operand2 = operands.top();
                operands.pop();
                string operand1 = operands.top();
                operands.pop();
                operands.push(operand1 + operand2 + ops.top().first);
                ops.pop();
            }
            ops.push(make_pair(c, priority));
        }
    }

    while (!ops.empty()) {
        string operand2 = operands.top();
        operands.pop();
        string operand1 = operands.top();
        operands.pop();
        char op = ops.top().first;
        ops.pop();

        operands.push(operand1 + operand2 + op);
    }

    cout << operands.top();

    return 0;
}