#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<int> q;
    int n; cin >> n;

    while (n--) {
        int x; cin >> x;

        if (x) {
            q.push(x);
        } else {
            if (q.empty()) {
                cout << "0\n";
            } else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
    }
}
