#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, a, b, c, d, ans, price, cnt;

    cin >> n >> a >> b >> c >> d;


    // b / a > d / c
    if (b * c > a * d) {
        swap(b, d);
        swap(a, c);
    }

    cnt = ((n - 1) / a + 1) * a;
    price = ((n - 1) / a + 1) * b;
    ans = price;

    ll i = 0, j = cnt / a;

    while (i < a) {
        i++;
        cnt += c;
        price += d;

        while (cnt - a >= n && j > 0) {
            cnt -= a;
            price -= b;
            j--;
        } 

        ans = min(ans, price);
    }

    cout << ans;
}
