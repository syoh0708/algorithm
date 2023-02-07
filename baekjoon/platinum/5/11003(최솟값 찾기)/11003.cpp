#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l, a, min_val = 1e9 + 1, min_idx = -1;
    deque<int> val_deq, idx_deq;

    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        cin >> a;

        if (a < min_val) {
            min_idx = i + l - 1;
            min_val = a;
            
            while (!val_deq.empty()) {
                val_deq.pop_front();
                idx_deq.pop_front();
            }
        } else {
            while (!val_deq.empty() && val_deq.back() >= a) {
                val_deq.pop_back();
                idx_deq.pop_back();
            }

            val_deq.push_back(a);
            idx_deq.push_back(i + l - 1);
        }

        if (i > min_idx) {
            min_val = val_deq.front();
            val_deq.pop_front();
            min_idx = idx_deq.front();
            idx_deq.pop_front();
        }

        cout << min_val << ' ';
    }
}
