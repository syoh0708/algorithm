#include <iostream>

using namespace std;

int prime[1000000];
bool composite[1000005] = {true, true};

int main(void) {
    int t, pn = 0;

    cin >> t;

    for (int i = 2; i <= 1000000; i++) {
        if (composite[i]) {
            continue;
        }

        prime[pn++] = i;

        for (int j = i * i; i < 1000 && j < 1000000; j += i) {
            composite[j] = true;
        }
    }


    while (t--) {
        int even, i = 0, count = 0;

        cin >> even;

        while (prime[i] <= even / 2) {
            if (!composite[even - prime[i++]]) {
                count++;
            }
        }

        cout << count << '\n';
    }

    return 0;
}