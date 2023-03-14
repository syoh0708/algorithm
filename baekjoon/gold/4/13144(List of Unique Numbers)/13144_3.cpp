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

    int st = 0, end = 0;    
    long long ans = 0;

    while (end < n) {
        if (s.find(a[end]) != s.end()) {
            while (a[st] != a[end]) {
                ans += (end - st);
                s.erase(a[st++]);
            }
            ans += (end - st);

            st++;
            end++;
        } else {
            s.insert(a[end++]);
        }
    }

    while (st < n) {
        ans += (end - st);
        st++;
    }

    cout << ans;
}
