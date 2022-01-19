#include<iostream>

using namespace std;

bool used[10];
int seq[10];

void find_or_print_permutation(int n, int idx) {
    if (n == idx) {
        for (int i = 0; i < n; i++) {
            cout << seq[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;

        used[i] = true;
        seq[idx] = i;
        find_or_print_permutation(n, idx + 1);
        used[i] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    find_or_print_permutation(n, 0);

    return 0;
}
