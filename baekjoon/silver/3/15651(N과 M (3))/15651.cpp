#include<iostream>

using namespace std;

int seq[10];

void find_or_print_seq(int max, int count, int curr_idx) {
    if (curr_idx == count) {
        for (int i = 0; i < count; i++) {
            cout << seq[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= max; i++) {
        seq[curr_idx] = i;
        find_or_print_seq(max, count, curr_idx + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    find_or_print_seq(n, m, 0);

    return 0;
}