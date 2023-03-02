#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    unordered_set<string> a;

    cin >> s;

    int size = s.size();

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j <= size; j++) {
            a.insert(s.substr(i, j - i));
        }
    }

    cout << a.size();
}
