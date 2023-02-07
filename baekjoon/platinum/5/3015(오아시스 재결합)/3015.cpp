#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, prev_height, duplicate_cnt, cnt, a; cin >> n;
    long long ans = 0;
    stack<pair<int, int>> s;

    while (n--) {
        cin >> a;

        if (!s.empty()) {
            pair<int, int>& cur = s.top();
            prev_height = cur.first;
            cnt = cur.second;
            duplicate_cnt = 1;

            while (prev_height < a) {
                ans += (cnt + 1);
                s.pop();

                if (s.empty()) break;

                pair<int, int>& tmp = s.top();
                tmp.second += duplicate_cnt;
                if (prev_height == tmp.first) {
                    duplicate_cnt++;
                } else {
                    prev_height = tmp.first;
                    duplicate_cnt = 1;
                }
                prev_height = tmp.first;
                cnt = tmp.second;
            }
        }

        s.push({a, 0});
    }

    prev_height = s.top().first;
    duplicate_cnt = 1;
    s.pop();

    while (!s.empty()) {
        pair<int, int>& cur = s.top(); s.pop();
        cur.second += duplicate_cnt;
        if (prev_height == cur.first) {
            duplicate_cnt++;
        } else {
            duplicate_cnt = 1;
            prev_height = cur.first;
        }
        ans += cur.second;
    }

    cout << ans;
}
