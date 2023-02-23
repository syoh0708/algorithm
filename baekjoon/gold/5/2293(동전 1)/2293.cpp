#include <bits/stdc++.h>

using namespace std;

int coin[100];
int d[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;

    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> coin[i];   
    }

    d[0] = 1;

    for (int i = 0; i < n; i++) {
        int cur = coin[i];
        for (int j = 0; j <= k; j++) {
            if (j - cur >= 0) d[j] += d[j - cur];
        }
    }

    cout << d[k];
}
