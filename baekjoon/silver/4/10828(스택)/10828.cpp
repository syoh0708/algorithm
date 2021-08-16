#include <iostream>
#include <string>
using namespace std;

struct Stack {
    int data[10000];
    int size;

    Stack() {
        size = 0;
    }

    void push(int num) {
        data[size] = num;
        size++;
    }

    bool empty() {
        return size == 0;
    }
    
    int pop() {
        if (empty()) {
            return -1;
        }

        return data[--size];
    }

    int top() {
        if (empty()) {
            return -1;
        }

        return data[size - 1];
    }
};

int main(void) {

    int n;
    Stack s;
    cin >> n;

    while (n--) {
        string cmd;

        cin >> cmd;
        if (cmd == "push") {
            int num;

            cin >> num;
            s.push(num);
        } else if (cmd == "pop") {
            cout << s.pop() << '\n';
        } else if (cmd == "size") {
            cout << s.size << '\n';
        } else if (cmd == "empty") {
            cout << s.empty() << '\n';
        } else if (cmd == "top") {
            cout << s.top() << '\n'; 
        }
    }

    return 0;
}