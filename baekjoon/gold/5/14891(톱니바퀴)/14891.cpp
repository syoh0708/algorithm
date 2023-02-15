#include <bits/stdc++.h>

using namespace std;

deque<bool> d[4];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string tmp;
    int n, c, r;

    for (int i = 0; i < 4; i++) {
        cin >> tmp;
        for (int j = 0; j < 8; j++) {
            d[i].push_back(tmp[j] == '1');
        }
    }

    cin >> n;

    while (n--) {
        cin >> c >> r;
        int rotate[4] = {};

        c--;
        int right = c, left = c, right_r = r, left_r = r;
        rotate[c] = r;

        for (int i = 0; i < 3; i++) {
            right++; left--;
            if (right < 4) {
                if (d[right - 1].at(2) == d[right].at(6)) {
                    right_r = 0;
                } else {
                    right_r = -right_r;
                }
                rotate[right] = right_r;
            }
            if (left >= 0) {
                if (d[left + 1].at(6) == d[left].at(2)) {
                    left_r = 0;
                } else {
                    left_r = -left_r;
                }
                rotate[left] = left_r;
            }
        }

        for (int i = 0; i < 4; i++) {
            if (rotate[i] == 1) {
                int back = d[i].back(); d[i].pop_back();
                d[i].push_front(back);
            } else if (rotate[i] == -1) {
                int front = d[i].front(); d[i].pop_front();
                d[i].push_back(front);
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < 4; i++) {
        ans += d[i].front() << i;
    }

    cout << ans;
}
