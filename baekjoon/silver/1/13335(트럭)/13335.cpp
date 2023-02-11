#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, w, l, truck, time = 0, cur_load = 0;

    cin >> n >> w >> l;

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        cin >> truck;
        cur_load += truck;

        if (cur_load <= l) {
            q.push({truck, ++time});
        } else {
            while (1) {
                pair<int, int> cur = q.front(); q.pop();
                cur_load -= cur.first;

                if (cur_load <= l && q.size() < w) {
                    time = max(cur.second + w, time + 1);
                    q.push({truck, time});
                    break;
                }
            }
        }
    }

    cout << time + w;
}
