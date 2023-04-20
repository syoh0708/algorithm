#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n;
ll d[10];
vector<int> digits;

// x = 200이라면 000 ~ 199까지의 수 digit count를 더해주는 함수
void add_cnt(ll x) {
    ll p, q = 0, ten2q = 1; 

    while (x > 9) {
        q++;
        ten2q *= 10;
        x /= 10;
    }

    p = x;

    for (int i = 0; i < p; i++) d[i] += ten2q;
    for (int i = 0; i < 10; i++) d[i] += p * q * ten2q / 10;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 2143
    cin >> n;

    ll tmp = n, idx = 0;

    while (tmp) {
        digits.push_back(tmp % 10);
        tmp /= 10;
    }

    // digits = {2, 1, 4, 3};
    reverse(digits.begin(), digits.end());

    n++;

    ll pow10 = 10;

    while (n / pow10) {
        ll cnt = n % pow10;

        n -= cnt;
        add_cnt(cnt);

        digits.pop_back();
        for (int digit : digits) d[digit] += cnt;
        pow10 *= 10;
    }

    // 1부터 n - 1까지의 수 카운트;
    // n = p * 10^q;
    // 1 ~ 10^q - 1 까지 
    // 1 ~ 9 : ;
    ll p, q = 0, ten2q = 1;
    tmp = n;

    while (tmp > 9) {
        q++;
        ten2q *= 10;
        tmp /= 10;
    }

    p = tmp;


    for (int i = 1; i < p; i++) d[i] += ten2q;
    for (int i = 0; i < 10; i++) d[i] += (n * q / 10);
    d[0] -= (ten2q - 1) / 9;

    for (int i = 0; i < 10; i++) cout << d[i] << ' ';
}
