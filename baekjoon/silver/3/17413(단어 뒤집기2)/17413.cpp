#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
    stack<char> s;
    string sentence;
    bool is_tag = false;

    getline(cin, sentence);
    sentence += '\n';

    for (char c : sentence) {
        if (is_tag) {
            if (c == '>') {
                is_tag = false;
            }
            cout << c;
            continue;
        }

        if (c == ' ' || c == '\n' || c == '<') {
            while (!s.empty()) {
                cout << s.top();
                s.pop();
            }

            if (c == '<') {
                is_tag = true;
            }
            cout << c;
        } else {
            s.push(c);
        }
    }

    return 0;
}