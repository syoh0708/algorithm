#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<string> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), [](const string& a, const string b) {
        if (a.size() != b.size()) {
            return a.size() < b.size();
        } else {
            return a < b;
        }
    });

    for (int i = 0; i < n; i++) {
        if (i == 0 || v[i - 1] != v[i]) {
            cout << v[i] << '\n';
        }
    }
}
