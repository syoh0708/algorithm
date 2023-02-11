#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;

    cin >> n;

    while (n--) {
        string str;

        cin >> str;

        list<char> password;

        auto iter = password.end();

        for (char c : str) {
            if (c == '<') {
                if (iter != password.begin()) {
                    iter--;
                }
            } else if (c == '>') {
                if (iter != password.end()) {
                    iter++;
                }
            } else if (c == '-') {
                if (iter != password.begin()) {
                    iter = password.erase(--iter);
                }
            } else {
                iter = password.insert(iter, c);
                iter++;
            }
        }

        for (iter = password.begin(); iter!=password.end(); iter++) { 
            cout << *iter;
        } 
        cout << '\n';
    }
}
