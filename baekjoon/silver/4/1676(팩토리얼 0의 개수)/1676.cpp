#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    int n, zero_count = 0;

    cin >> n;

    while (n) {
        n /= 5;
        zero_count += n;
    }

    cout << zero_count << '\n';
}
