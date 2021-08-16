#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(void) {
    int n;

    cin >> n;
    cin.ignore();

    while (n--) {
        string sentence;
        stack<char> word_stack;
        
        getline(cin, sentence);
        sentence += '\n';

        for (char c : sentence) {
            if (c == ' ' || c == '\n') {
                while (!word_stack.empty()) {
                    cout << word_stack.top();
                    word_stack.pop();
                }

                cout << c;
            } else {
                word_stack.push(c);
            }
        }
    }
    
    return 0;
}