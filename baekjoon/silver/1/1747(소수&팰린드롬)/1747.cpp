#include <bits/stdc++.h>

using namespace std;

int n;

bool is_palindrome(int x) {
    string str = to_string(x);
    int sz = str.size();

    for (int i = 0; i < sz; i++) {
        if (str[i] != str[sz - 1 - i]) return false;
    }
    
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

     cin >> n;

    vector<bool> is_prime(1'010'001, true);

    is_prime[1] = false;

    for (int i = 2; i * i <= 1'010'000; i++) {
        if (!is_prime[i]) continue;

        for (int j = i * i; j <= 1'010'000; j += i) {
            is_prime[j] = false;
        }
    }

    for (int i = n; i <= 1'010'000; i++) {
        if (is_prime[i] && is_palindrome(i)) {
            cout << i;
            return 0;
        }
    }
}
