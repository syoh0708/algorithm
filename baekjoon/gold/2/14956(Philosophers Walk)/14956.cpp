#include <bits/stdc++.h>

using namespace std;

pair<int, int> func(int n, int m) {
    if (n == 2) {
        if (m == 0) {
            return {0, 0};
        } else if (m == 1) {
            return {0, 1};
        } else if (m == 2) {
            return {1, 1}; 
        } else {
            return {1, 0};
        }
    }

    int criteria = n * n / 4;
    int q = m / criteria, r = m % criteria;
    pair<int, int> ans = func(n / 2, r);;

    if (q == 0) {
        return {ans.second, ans.first};
    } else if (q == 1) {
        return {ans.first, ans.second + n / 2};
    } else if (q == 2) {
        return {ans.first + n / 2, ans.second + n / 2};
    } else {
        return {n - 1 - ans.second, n / 2 - 1 - ans.first};
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;

    cin >> n >> m;

    pair<int, int> ans = func(n, m - 1);

    cout << ans.first + 1 << ' ' << ans.second + 1;
}
