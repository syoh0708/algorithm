#include<iostream>

using namespace std;

int candidate[14];
int seq[14];

void find_or_print_seq(int max, int curr, int idx) {
    if (idx == 6) {
        for(int i = 0; i < 6; i++) {
            cout << seq[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = curr; i <= max - (6 - idx); i++) {
        seq[idx] = candidate[i];
        find_or_print_seq(max, i + 1, idx + 1);
    }
}

int main(void) {
    while (true) {
        int n;

        cin >> n;

        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            cin >> candidate[i];
        }

        find_or_print_seq(n, 0, 0);
        cout << '\n';
    }

    return 0;
}
