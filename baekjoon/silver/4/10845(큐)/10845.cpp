#include <iostream>
#include <string>
using namespace std;

struct Queue {
    int data[10000];
    int begin, end;

    Queue() {
        begin = 0;
        end = 0;
    }

    void push(int num) {
        data[end++] = num;
    }

    bool empty() {
        return begin == end;
    }
    
    int pop() {
        if (empty()) {
            return -1;
        }

        return data[begin++];
    }

    int size() {
        return end - begin;
    }

    int front() {
        if (empty()) {
            return -1;
        }

        return data[begin];
    }

    int back() {
        if (empty()) {
            return -1;
        }

        return data[end - 1];
    }
};

int main(void) {

    int n;
    Queue q;
    cin >> n;

    while (n--) {
        string cmd;

        cin >> cmd;
        if (cmd == "push") {
            int num;

            cin >> num;
            q.push(num);
        } else if (cmd == "pop") {
            cout << q.pop() << '\n';
        } else if (cmd == "size") {
            cout << q.size() << '\n';
        } else if (cmd == "empty") {
            cout << q.empty() << '\n';
        } else if (cmd == "front") {
            cout << q.front() << '\n'; 
        } else if (cmd == "back") {
            cout << q.back() << '\n'; 
        }
    }

    return 0;
}