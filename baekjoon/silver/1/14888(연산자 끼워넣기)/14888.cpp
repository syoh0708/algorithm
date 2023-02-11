#include <bits/stdc++.h>

using namespace std;

int n; 
int arr[11];
int ops[4];
int max_val = -1000000000, min_val = 1000000000;

void func(int i, int cur) {
    if (i == n - 1) {
        for (int j = 0; j < 4; j++) {
            if (ops[j]) {
                if (j == 0) {
                    max_val = max(max_val, cur + arr[i]);
                    min_val = min(min_val, cur + arr[i]);
                } else if (j == 1) {
                    max_val = max(max_val, cur - arr[i]);
                    min_val = min(min_val, cur - arr[i]);
                } else if (j == 2) {
                    max_val = max(max_val, cur * arr[i]);
                    min_val = min(min_val, cur * arr[i]);
                } else {
                    max_val = max(max_val, cur / arr[i]);
                    min_val = min(min_val, cur / arr[i]);
                }
            }
        }
    }

    for (int j = 0; j < 4; j++) {
        if (ops[j]) {
            ops[j]--;
            if (j == 0) {
                func(i + 1, cur + arr[i]);
            } else if (j == 1) {
                func(i + 1, cur - arr[i]);
            } else if (j == 2) {
                func(i + 1, cur * arr[i]);
            } else {
                func(i + 1, cur / arr[i]);
            }
            ops[j]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> ops[0] >> ops[1] >> ops[2] >> ops[3];

    func(1, arr[0]);

    cout << max_val << '\n' << min_val;
}
