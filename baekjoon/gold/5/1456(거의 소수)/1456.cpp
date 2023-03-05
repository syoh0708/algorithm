#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> seive() {
    vector<ll> primes;
    vector<bool> is_prime(10000001, true);

    is_prime[1] = false;

    for (ll i = 2; i * i <= 10000000; i++) {
        if (!is_prime[i]) continue;

        for (ll j = i * i; j <= 10000000; j += i) {
            is_prime[j] = false;
        }
    }

    for (ll i = 2; i <= 10000000; i++) {
        if (is_prime[i]) primes.push_back(i);
    }

    return primes;
}

vector<ll> get_almost_primes(vector<ll>& primes, ll n) {
    vector<ll> almost_primes;

    for (ll prime : primes) {
        if (prime * prime > n) break;

        ll cur = prime;

        while (cur <= n / prime) {
            almost_primes.push_back(cur * prime);

            cur *= prime;
        }
    }

    sort(almost_primes.begin(), almost_primes.end());

    return almost_primes;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll a, b;

    cin >> a >> b;

    vector<ll> primes = seive();
    vector<ll> ap = get_almost_primes(primes, b);

    cout << upper_bound(ap.begin(), ap.end(), b) - upper_bound(ap.begin(), ap.end(), a - 1);
}
