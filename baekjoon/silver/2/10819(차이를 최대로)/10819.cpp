#include<iostream>

using namespace std;

int int_seq[10];
int seq[10];
bool used[10];

int max(int a, int b) {
    return a > b ? a : b;
}

int abs(int a) {
    return a > 0 ? a : -a;
}

int get_max_diff(int n, int curr) {
    if (n == curr) return 0;

    int max_diff = 0;

    for (int i = 0; i < n; i++) {
        if (used[i]) continue;

        used[i] = true;
        seq[curr] = int_seq[i];
        int curr_diff = curr > 0 ? abs(seq[curr] - seq[curr - 1]) : 0;
        int curr_max_diff = curr_diff + get_max_diff(n, curr + 1);
        max_diff = max(max_diff, curr_max_diff);
        used[i] = false;
    }

    return max_diff;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> int_seq[i];
    }

    cout << get_max_diff(n, 0) << '\n';

    return 0;
}
