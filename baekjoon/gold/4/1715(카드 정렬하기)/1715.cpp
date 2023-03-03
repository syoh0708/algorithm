#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    while (n--) {
        int x; cin >> x;

        pq.push(x);
    }

    int ans = 0;

    while (!pq.empty()) {
        int first = pq.top(); pq.pop();

        if (pq.empty()) {
            cout << ans;
            return 0;
        }

        int second = pq.top(); pq.pop();
        int sum = first + second;

        ans += sum;
        pq.push(sum);
    }
}
