#include <bits/stdc++.h>

using namespace std;

int a[1005];
unordered_set<int> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a, a + n);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n - 1; j++) s.insert(a[i] + a[j]);
    }

    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (s.find(a[i] - a[j]) != s.end()) {
                cout << a[i];
                
                return 0;
            }
        }
    }
}
