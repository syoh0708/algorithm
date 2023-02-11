#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    vector<string> v;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        v.push_back(s.substr(i));
    }
    
    sort(v.begin(), v.end());

    for (string str : v) {
        cout << str << '\n';
    }
}
