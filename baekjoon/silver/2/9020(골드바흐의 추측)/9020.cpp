#include <bits/stdc++.h>

using namespace std;

vector<bool> is_prime(10001, true);

vector<int> seive() {
    vector<int> primes;    

    is_prime[1] = false;

    for (int i = 2; i * i <= 10000; i++) {
        if (!is_prime[i]) continue;

        for (int j = i * i; j <= 10000; j += i) {
            is_prime[j] = false;
        }
    }

    for (int i = 2; i <= 10000; i++) {
        if (is_prime[i]) primes.push_back(i);
    }

    return primes;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;

    vector<int> primes = seive();

    while (t--) {
        int p; cin >> p;

        int i = p / 2, j = 0;

        auto it = lower_bound(primes.begin(), primes.end(), i);

        while (1) {
            if (is_prime[p - *(it + j)]) {
                cout << p - *(it + j) << ' ' << *(it + j) << '\n';
                break;
            }
            j++;
        }

    }
}
