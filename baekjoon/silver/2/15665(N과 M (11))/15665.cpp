#include<iostream>
#include<set>

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

    for (int i = 0; i < max; i++) {
        idx_seq[curr_idx] = i;
        find_or_print_seq(max, count, curr_idx + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x;
    set<int> s;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }

    n = 0;

    for (int x: s) {
        int_seq[n++] = x;
    }

    find_or_print_seq(n, m, 0);

    return 0;
}