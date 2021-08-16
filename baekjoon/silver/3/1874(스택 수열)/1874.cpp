#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(void) {
    int n, element, i = 1;
    stack<int> s;
    string instructions = "";

    cin >> n;

    while (n--) {
        cin >> element;

        if (i > element) {
            if (!s.empty() && s.top() == element) {
                s.pop();
                instructions += '-';
            } else {
                cout << "NO" << '\n';
                return 0;
            }
        }

        while (i <= element) {
            s.push(i);
            instructions += '+';
            i++;
        }

        if (i == element + 1) {
            s.pop();
            instructions += '-';
        }
    }

    for (char c : instructions) {
        cout << c << '\n';
    }

    return 0;
}