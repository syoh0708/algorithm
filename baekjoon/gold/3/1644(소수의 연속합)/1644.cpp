#include <bits/stdc++.h>

using namespace std;

vector<int> seive(int n) {
    vector<int> primes;
    vector<bool> is_prime(4'000'001, true);

    is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (!is_prime[i]) continue;

        for (int j = i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) primes.push_back(i);
    }

    return primes;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;

    vector<int> primes = seive(n);
    int sz = primes.size();

    int i = 0, j = 0, sum = 0, ans = 0;

    while (1) {
        if (sum < n) {
            if (i == sz) break;

            sum += primes[i++];
        } else {
            sum -= primes[j++];
        }

        if (sum == n) ans++;
    }

    cout << ans;
}
