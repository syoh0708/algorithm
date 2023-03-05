#include <bits/stdc++.h>

using namespace std;

vector<bool> is_prime(247000, true);

vector<int> seive() {
    int n = 246999;
    vector<int> primes;
    
    is_prime[1] = false;

    for (int i = 2; i * i < n; i++) {
        if (!is_prime[i]) continue;

        for (int j = i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }

    for (int i = 2; i < n; i++) {
        if (is_prime[i]) primes.push_back(i);
    }

    return primes;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> primes = seive();

    while (1) {
        int n; cin >> n;

        if (!n) return 0;

        cout << upper_bound(primes.begin(), primes.end(), 2 * n) - upper_bound(primes.begin(), primes.end(), n) << '\n';
    }
}
