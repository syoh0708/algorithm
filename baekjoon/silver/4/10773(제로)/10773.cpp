#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k, n, sum = 0;
    stack<int> s;

    cin >> k;

    while (k--) {
        cin >> n;

        if (n) {
            s.push(n);
        } else {
            s.pop();
        }
    }

    while (!s.empty()) {
        sum += s.top();
        s.pop();
    } 

    cout << sum;
}
