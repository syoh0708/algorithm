#include <bits/stdc++.h>

using namespace std;

pair<int, int> a[100005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;

    sort(a, a + n);

    int i = 0, end = 0, ans = 0;

    while (i < n) {
        if (a[i].second >= end) {
            ans++;
            end = a[i].first;
        }
        i++;
    }

    cout << ans;
}
