#include <bits/stdc++.h>

using namespace std;

int n, k, ans;
int a[105];
queue<int> q[105];
set<int> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> a[i];

        q[a[i]].push(i);
    }

    for (int i = 0; i < k; i++) {
        int cur = a[i];
        q[a[i]].pop();

        if (s.find(a[i]) != s.end()) continue;
        if (s.size() < n) s.insert(a[i]);
        else {
            int max_val = 0, pop;
            for (int x : s) {
                if (q[x].empty()) {
                    pop = x;
                    break;
                }
                if (q[x].front() > max_val) {
                    max_val = q[x].front();
                    pop = x;
                }
            }

            ans++;
            s.erase(pop);
            s.insert(a[i]);
        }
    }

    cout << ans;
}
