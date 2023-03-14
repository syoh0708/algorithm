#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[2049];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;

    int i = 0;

    for (int j = 1; j <= 10; j++) {
        vector<bool> v((10 - j), false);

        for (int k = 0; k < j; k++) v.push_back(true);

        do {
            for (int k = 0; k < 10; k++) {
                if (v[k]) {
                    a[i] *= 10;
                    a[i] += 9 - k;
                }
            }

            i++;
        } while (next_permutation(v.begin(), v.end()));
    }

    cout << (n > 1022 ? -1 : a[n]);
}
