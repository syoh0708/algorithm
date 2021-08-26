#include <cstdlib>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
    int n;
    stack<int> s;

    cin >> n;

    if (n == 0) {
        cout << 0;
    }

    while (n) {
        int r = abs(n % 2);
        s.push(r);
        n -= r;
        n /= -2;
    }

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}
