#include <bits/stdc++.h>

using namespace std;

int a[100002];
unordered_set<int> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int st = 0, mid = 0, end = 0;
    long long ans = 0;

    while (end < n) {
        if (s.find(a[end]) != s.end()) {

            ans += ((end - st) * (end - st - 1) / 2);

            while (a[st] != a[end]) {
                s.erase(a[st++]);
            }
            st++;

            mid = end++;
            ans -= ((mid - st) * (mid - st - 1) / 2);
        } else {
            s.insert(a[end++]);
        }
    }
    ans += ((end - st) * (end - st - 1) / 2);
    ans += n;

    cout << ans;
}

    // cout << "1. st = " << st << ", mid = " << mid << ", end = " << end << ", ans = " << ans << '\n';
