#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string s;
    int l, i = 0, digit = 0;

    cin >> s;

    l = s.size();

    while (l--) {
        digit += s[i] - '0';

        if (l % 3 == 0) {
            cout << digit;
            digit = 0;
        } else {
            digit *= 2;
        }

        i++;
    }

    return 0;
}
