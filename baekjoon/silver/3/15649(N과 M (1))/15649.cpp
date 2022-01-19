#include<iostream>

using namespace std;

bool used[50];
int seq[50];

void find_or_print_seq(int max, int count, int curr) {
    if (curr == count) {
        for (int i = 0; i < count; i++) {
            printf("%d ", seq[i]);
        }

        printf("\n");
        return;
    }

    for (int i = 1; i <= max; i++) {
        if (used[i]) {
            continue;
        }

        used[i] = true;
        seq[curr] = i;
        find_or_print_seq(max, count, curr + 1);
        used[i] = false;
    }
}


int main(void) {
    int n, m;

    cin >> n >> m;

    find_or_print_seq(n, m, 0);

    return 0;
}
