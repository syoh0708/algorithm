#include <bits/stdc++.h>

using namespace std;

int n;
bool sk[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    sk[1] = true;
    sk[2] = false;
    sk[3] = true;
    sk[4] = true;

    for (int i = 5; i <= n; i++) {
        sk[i] = !(sk[i - 1] && sk[i - 3] && sk[i - 4]);
    }

    cout << (sk[n] ? "SK" : "CY");
}
