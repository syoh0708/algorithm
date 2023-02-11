#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    string s;
    vector<long long> v;

    cin >> n;

    while (n--) {
        cin >> s;
        reverse(s.begin(), s.end());
        v.push_back(stoll(s));
    }

    sort(v.begin(), v.end());
    
    for (long long i : v) {
        cout << i << '\n';
    }
}
