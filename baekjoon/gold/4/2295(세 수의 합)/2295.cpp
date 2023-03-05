#include <bits/stdc++.h>

using namespace std;

int num[1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    set<int> s;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
        s.insert(num[i]);
    }

    sort(num, num + n);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            for (int k = j; k >= 0; k--) {
                int target = num[i] - num[j] - num[k];

                if (target <= 0) continue;

                auto it = s.find(target);

                if (it != s.end()) {
                    cout << num[i];
                    return 0;
                }
            }
        }
    }
}
