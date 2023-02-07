#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, a;

    while (1) {
        stack<pair<int, int>> s;
        ll max_area = 0;

        cin >> n;

        if (!n) break;

        for (int i = 0; i < n; i++) {
            cin >> a;

            int idx = i;
            
            while (!s.empty() && s.top().second > a) {
                pair<int, int> p = s.top();
                s.pop();

                max_area = max(1LL * (i - p.first) * p.second, max_area);
                idx = p.first;
            }

            if (s.empty()) {
                s.push(make_pair(0, a));                
            } else if (a > s.top().second) {
                s.push(make_pair(idx, a));
            }
        }

        while (!s.empty()) {
                pair<int, int> p = s.top();
                s.pop();

                max_area = max(1LL * (n - p.first) * p.second, max_area);
        }

        cout << max_area << '\n';
    }
}
