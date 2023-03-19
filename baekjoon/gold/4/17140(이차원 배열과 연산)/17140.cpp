#include <bits/stdc++.h>

using namespace std;

int a[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int r, c, k, ans = 0, rr = 3, cc = 3; 
    
    cin >> r >> c >> k;
    r--; c--;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    while (ans < 101) {
        if (a[r][c] == k) break;
        
        if (rr >= cc) {
            int max_cc = cc;
            for (int i = 0; i < rr; i++) {
                unordered_map<int, int> m;
                vector<pair<int, int>> v;
                for (int j = 0; j < cc; j++) {
                    if (!a[i][j]) continue;

                    m[a[i][j]]++;
                }

                for (auto x : m) v.push_back({x.second, x.first});
                sort(v.begin(), v.end());
                int k = 0;
                for (auto x : v) {
                    a[i][k++] = x.second;
                    a[i][k++] = x.first;
                }

                max_cc = max(max_cc, k);
                fill(a[i] + k, a[i] + 100, 0);
            }     
            cc = min(max_cc, 100);       
        } else {
            int max_rr = rr;
            for (int j = 0; j < cc; j++) {
                unordered_map<int, int> m;
                vector<pair<int, int>> v;
                for (int i = 0; i < cc; i++) {
                    if (!a[i][j]) continue;

                    m[a[i][j]]++;
                }

                for (auto x : m) v.push_back({x.second, x.first});
                sort(v.begin(), v.end());
                int k = 0;
                for (auto x : v) {
                    a[k++][j] = x.second;
                    a[k++][j] = x.first;
                }

                max_rr = max(max_rr, k);
                while (k < 100) a[k++][j] = 0;                
            }
            rr = min(max_rr, 100);
        }

        ans++;
    }

    cout << (ans == 101 ? -1 : ans);
}
