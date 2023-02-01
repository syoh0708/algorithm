#include <bits/stdc++.h>

using namespace std;

const int MAX_NUM = 1000000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a;
    vector<bool> v(MAX_NUM * 2 + 1, false);
    cin >> n;

    while (n--) {
        cin >> a;

        v[a + MAX_NUM] = true;
    }
    
    for (int i = MAX_NUM; i >= -MAX_NUM; i--) {
        if (v[i + MAX_NUM]) cout << i << '\n';
    }
}
