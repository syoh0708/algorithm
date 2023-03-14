#include <bits/stdc++.h>

using namespace std;

int a[200000];
unordered_map<int, int> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, ans = 0, cur = 0; cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int j = 0;
    for (int i = 0; i < n; i++) {
        m[a[i]]++;
        cur++;

        if (m[a[i]] <= k) {
            if (cur > ans) ans = cur;
        } else {
            while (m[a[i]] > k) {
                m[a[j++]]--;
                cur--;
            }
        }
    }

    cout << ans;
}
