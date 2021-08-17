#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(void) {
    string str;
    stack<char> s;
    int count = 0;
    bool open = false;

    cin >> str;

    for (char c : str) {
        if (c == '(') {
            open = true;
            s.push(c);
        } else {
            s.pop();
            if (open) {
                count += s.size();
            } else {
                count++;
            }
            open = false;
        }
    }

    cout << count << '\n';
}