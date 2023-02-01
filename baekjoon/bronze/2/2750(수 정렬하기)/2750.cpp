#include <bits/stdc++.h>

using namespace std;

bool exist[2001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, a;
    cin >> n;

    while (n--) {
        cin >> a;
        exist[a + 1000] = true;
    }

    for (int i = -1000; i < 1001; i++) {
        if (exist[i + 1000]) cout << i << '\n';
    }
}
