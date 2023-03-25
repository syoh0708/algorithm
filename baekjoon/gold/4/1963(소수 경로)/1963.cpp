#include <bits/stdc++.h>

using namespace std;

unordered_set<int> primes;

int change(int prime, int ten_pow, int digit) {
    int val = 1, val2;

    while (ten_pow--) val *= 10;

    val2 = prime / val % 10;

    prime += (digit - val2) * val;

    return prime;
}

void seive() {
    vector<bool> is_prime(10001, true);
    is_prime[1] = false;

    for (int i = 2; i <= 100; i++) {
        if (!is_prime[i]) continue;

        for (int j = i * i; j <= 10000; j += i) is_prime[j] = false;
    }

    for (int i = 1000; i < 10000; i++) {
        if (is_prime[i]) primes.insert(i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    seive();

    while (t--) {
        int p1, p2; cin >> p1 >> p2;

        queue<pair<int, int>> q;
        vector<bool> vis(10001);
        int ans = -1;

        vis[p1] = true;
        q.push({p1, 0});

        while (!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();
            int prime = cur.first;
            int dist = cur.second;

            if (prime == p2) {
                ans = dist;
                break;
            }

            for (int pow = 0; pow < 4; pow++) {
                for (int digit = 0; digit < 10; digit++) {
                    if (pow + digit == 0) continue;

                    int changed = change(prime, pow, digit);

                    if (prime == changed) continue;
                    if (primes.find(changed) == primes.end() || vis[changed]) continue;

                    vis[changed] = true;
                    q.push({changed, dist + 1});
                } 
            }
        }

        if (ans >= 0) cout << ans << '\n';
        else cout << "Impossible\n";
    }
}
