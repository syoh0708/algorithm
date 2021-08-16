#include <iostream>
#include <string>
using namespace std;

struct Deque {
    int data[20000];
    int begin, end;

    Deque() {
        begin = 10000;
        end = 10000;
    }

    void push_front(int num) {
        data[--begin] = num;
    }

    void push_back(int num) {
        data[end++] = num;
    }

    bool empty() {
        return begin == end;
    }
    
    int pop_front() {
        if (empty()) {
            return -1;
        }

        return data[begin++];
    }

    int pop_back() {
        if (empty()) {
            return -1;
        }

        return data[--end];
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
    Deque d;
    cin >> n;

    while (n--) {
        string cmd;

        cin >> cmd;
        if (cmd == "push_front") {
            int num;

            cin >> num;
            d.push_front(num);
        } else if (cmd == "push_back") {
            int num;

            cin >> num;
            d.push_back(num);
        } else if (cmd == "pop_front") {
            cout << d.pop_front() << '\n';
        } else if (cmd == "pop_back") {
            cout << d.pop_back() << '\n';
        } else if (cmd == "size") {
            cout << d.size() << '\n';
        } else if (cmd == "empty") {
            cout << d.empty() << '\n';
        } else if (cmd == "front") {
            cout << d.front() << '\n'; 
        } else if (cmd == "back") {
            cout << d.back() << '\n'; 
        }
    }

    return 0;
}