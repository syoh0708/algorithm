#include<iostream>
#include<algorithm>

using namespace std;

bool used[10];
int idx_seq[10];
int int_seq[10];

void find_or_print_seq(int max, int count, int curr_idx) {
    if (curr_idx == count) {
        for (int i = 0; i < count; i++) {
            cout << int_seq[idx_seq[i]] << ' ';
        }

        cout << '\n';
        return;
    }

    for (int i = 1; i <= max; i++) {
        if (used[i] || int_seq[i] == int_seq[idx_seq[curr_idx]]) continue;

        used[i] = true;
        idx_seq[curr_idx] = i;
        idx_seq[curr_idx + 1] = 0;
        find_or_print_seq(max, count, curr_idx + 1);
        used[i] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> int_seq[i];
    }

    sort(int_seq + 1, int_seq + n + 1);

    find_or_print_seq(n, m, 0);

    return 0;
}