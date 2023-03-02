#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll, ll> arr;
ll n, p, q;

ll func(ll n) {
    if (arr.find(n) != arr.end()) return arr[n];
    ll tmp = func(n / p);
    arr[n / p] = tmp;
    tmp = func(n / q);
    arr[n / q] = tmp;

    return arr[n / p] + arr[n / q];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    cin >> n >> p >> q;

    arr[0] = 1;
    for (int i = 1; i < 1000; i++) {
        arr[i] = arr[i / p] + arr[i / q];
    }

    cout << func(n);
}
