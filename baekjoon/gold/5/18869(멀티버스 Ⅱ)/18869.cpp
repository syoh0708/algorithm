#include <bits/stdc++.h>

using namespace std;

int p[100][10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m, n, ans = 0; cin >> m >> n;

    for (int i = 0; i < m; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
            v.push_back(p[i][j]);
        }

        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int j = 0; j < n; j++) p[i][j] = lower_bound(v.begin(), v.end(), p[i][j]) - v.begin();
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            ans++;
            for (int k = 0; k < n; k++) {
                if (p[i][k] != p[j][k]) {
                    ans--;
                    break;
                }
            }
        }
    }

    cout << ans;
}
