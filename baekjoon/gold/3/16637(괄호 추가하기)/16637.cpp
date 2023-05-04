#include <bits/stdc++.h>

using namespace std;

int n, ans;
string expr;
int num[15];
char ops[15];

int calc(int mask) {
    int tmp_num[15] = {};
    char tmp_ops[15] = {};

    for (int i = 0; i <= n / 2; i++) tmp_num[i] = num[i];
    for (int i = 0; i < n / 2; i++) tmp_ops[i] = ops[i];
    
    int i = 0;

    while (mask) {
        if (mask % 2) {
            if (tmp_ops[i] == '+') tmp_num[i] += tmp_num[i + 1];
            else if (tmp_ops[i] == '-') tmp_num[i] -= tmp_num[i + 1];
            else tmp_num[i] *= tmp_num[i + 1];

            tmp_num[i + 1] = 0;
            tmp_ops[i] = '+';
        }

        i++;
        mask /= 2;
    }

    int val = tmp_num[0];

    for (int i = 0; i < n / 2; i++) {
        if (tmp_ops[i] == '+') val += tmp_num[i + 1];
        else if (tmp_ops[i] == '-') val -= tmp_num[i + 1];
        else val *= tmp_num[i + 1];
    }

    return val;
}

bool is_valid(int k) {
    while (k) {
        if (k % 4 == 3) return false;

        k /= 2;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> expr;
    
    for (int i = 0; i < n; i++) {
        if (i % 2) ops[i / 2] = expr[i];
        else num[i / 2] = expr[i] - '0';
    }

    ans = calc(0);

    for (int i = 1; i < (1 << (n / 2)); i++) {
        if (!is_valid(i)) continue;

        ans = max(ans, calc(i));
    }

    cout << ans;
}
