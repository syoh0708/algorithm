#include <iostream>

using namespace std;

long long a[1000001];

int main(void) {
    int t;

    cin >> t;

    a[1] = 1;
    a[2] = 2;
    a[3] = 4;

    for (int i = 4; i <= 1000000; i++) {
        a[i] = (a[i-1] + a[i-2] + a[i-3]) % 1000000009LL;
    }

    while (t--) {
        int n;

        cin >> n;
        cout << a[n] << '\n';
    }

    return 0;
}