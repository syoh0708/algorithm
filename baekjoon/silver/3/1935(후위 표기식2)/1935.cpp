#include <iostream>
#include <stack>
#include <iomanip>

using namespace std;


int main(void) {
    int n;
    double variables[26];
    string expr;
    stack<double> s;
    
    cin >> n;
    cin >> expr;
    for (int i = 0; i < n; i++) {
        cin >> variables[i];
    }

    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] > 64 && expr[i] < 91) {
            s.push(variables[expr[i] - 65]);
        } else {
            double a, b;

            b = s.top();
            s.pop();
            a = s.top();
            s.pop();

            switch (expr[i]) {
                case '+':
                    s.push(a + b);
                    break;
                
                case '-':
                    s.push(a - b);
                    break;

                case '*':
                    s.push(a * b);
                    break;

                case '/':
                    s.push(a / b);
                    break;

                default:
                    break;
            }
        }
    }

     cout << fixed << setprecision(2) << s.top() << '\n';

    return 0;
}