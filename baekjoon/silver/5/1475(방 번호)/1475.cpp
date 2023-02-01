#include <bits/stdc++.h>

using namespace std;

int digit_cnt[10];

int main()
{
    int n;

    cin >> n;

    while (n) {
        digit_cnt[n % 10]++;

        n /= 10;
    }

    digit_cnt[6] = (digit_cnt[6] + digit_cnt[9] + 1) / 2;

    cout << *max_element(digit_cnt, digit_cnt + 9);
}
