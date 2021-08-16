#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(void) {
    string init_string;
    stack<char> leftside, rightside;
    int n;

    cin >> init_string;

    for (char c : init_string) 
        leftside.push(c);

    cin >> n;
    cin.ignore();

    while (n--) {
        string instruction;
        
        getline(cin, instruction);
        
        if (instruction[0] == 'L') {
            if (!leftside.empty()) {
                rightside.push(leftside.top());
                leftside.pop();
            }
        } else if (instruction[0] == 'D') {
            if (!rightside.empty()) {
                leftside.push(rightside.top());
                rightside.pop();
            }
        } else if (instruction[0] == 'B') {
            if (!leftside.empty()) {
                leftside.pop();
            }
        } else {
            leftside.push(instruction[2]);
        }
    }

    while (!leftside.empty()) {
        rightside.push(leftside.top());
        leftside.pop();
    }

    while (!rightside.empty()) {
        cout << rightside.top();
        rightside.pop();
    }

    cout << '\n';

    return 0;
}