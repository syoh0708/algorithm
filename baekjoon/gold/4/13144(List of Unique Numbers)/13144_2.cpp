#include <bits/stdc++.h>

using namespace std;

int a[100000];
unordered_set<int> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int st = 0, cnt = 0, end = 0;
    long long ans = n * (n + 1) / 2;

    while (end < n) {
        if (s.find(a[end]) != s.end()) {
            while (a[st] != a[end]) {
                s.erase(a[st++]);
                cnt++;
            }
            st++;
            cnt++;

            ans -= cnt * (n - end);
            end++;
            cnt = 0;
        } else {
            s.insert(a[end++]);
        }
    }

    cout << ans;
}
