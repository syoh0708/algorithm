#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;

    int t = n * n;

    while (t--) {
        int x; cin >> x;

        q.push(x);

        if (q.size() > n) q.pop();
    }
    
    cout << q.top();
}
