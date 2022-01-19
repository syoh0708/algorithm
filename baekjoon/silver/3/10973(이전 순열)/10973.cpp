#include<iostream>

using namespace std;

int seq[10005];
bool used[10005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, curr = -1;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    for (int i = 0; i < n - 1; i++) {
        if (seq[i] > seq[i + 1]) {
            curr = i;
        }
    }

    if (curr == -1) {
        printf("%d", -1);
        return 0;
    }

    for (int i = 0; i < curr; i++) {
        cout << seq[i] << ' ';
        used[seq[i]] = true;
    }

    for (int i = seq[curr] - 1; i > 0; i--) {
        if (!used[i]) {
            cout << i << ' ';
            used[i] = true;
            break;
        }
    }

    for (int i = n; i > 0; i--) {
        if (!used[i]) {
            cout << i << ' ';
        }
    }
}
