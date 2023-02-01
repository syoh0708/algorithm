#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, a;

    cin >> n;

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (q.size() > 1) {
        q.pop();
        a = q.front();
        q.pop();
        q.push(a);
    }

    cout << q.front();
}
