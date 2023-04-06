#include <bits/stdc++.h>

using namespace std;

int n;
long long ans;
stack<pair<int, int>> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--) {
        int a; cin >> a;

        while (!s.empty() && s.top().first <= a) {
            pair<int, int> tmp = s.top(); s.pop();
            ans += tmp.second;
            if (!s.empty()) s.top().second += (tmp.second + 1);
        }

        s.push({a, 0});
    }

    while (!s.empty()) {
        pair<int, int> tmp = s.top();
        ans += tmp.second;
        s.pop();
        if (!s.empty()) s.top().second += (tmp.second + 1);
    }

    cout << ans;
}
