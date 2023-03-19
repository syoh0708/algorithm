#include <bits/stdc++.h>

using namespace std;

int a[50][9];
int n, max_score;

int calc_score(vector<int>& order) {
    int score = 0, cur = 0;
    vector<int> real_order;
    for (int i = 0; i < 3; i++) real_order.push_back(order[i]);
    real_order.push_back(0);
    for (int i = 3; i < 8; i++) real_order.push_back(order[i]);

    for (int i = 0; i < n; i++) {
        int out = 0;
        queue<int> q;

        while (out < 3) {            
            int ball = a[i][real_order[cur]];
            cur = (cur + 1) % 9;

            if (ball == 0) out++;
            else q.push(ball);
        }

        int sz = q.size();

        for (int j = 0; j < sz - 3; j++) {
            score++;
            q.pop();
        }

        int j = 0, tmp[3] = {};
        while (!q.empty()) {
            tmp[j++] = q.front(); q.pop();
        }

        if (tmp[0] + tmp[1] + tmp[2] > 3) score++;
        if (tmp[1] + tmp[2] > 3) score++;
        if (tmp[2] > 3) score++;
    }

    return score;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    do {
        max_score = max(max_score, calc_score(v));
    } while (next_permutation(v.begin(), v.end()));

    cout << max_score;
}
