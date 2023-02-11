#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll arr[100000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, val, ans, cur_cnt = 1, max_cnt = 0; 
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    val = arr[0];
    ans = val;
    for (int i = 1; i < n; i++) {
        if (val == arr[i]) {
            cur_cnt++;
        } else {
            if (cur_cnt > max_cnt) {
                max_cnt = cur_cnt;
                ans = val;
            }
            val = arr[i];
            cur_cnt = 1;
        }
    }

    if (cur_cnt > max_cnt) ans = arr[n - 1];

    cout << ans;
}
