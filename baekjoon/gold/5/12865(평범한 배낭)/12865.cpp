#include <bits/stdc++.h>

using namespace std;

int n, k;
int d[1'000'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    while (n--) {
        int w, v; cin >> w >> v;

        for (int i = k - w; i > 0; i--) {
            if (d[i] && d[i] + v > d[i + w]) d[i + w] = d[i] + v;
        }

        d[w] = max(d[w], v);
    }

    cout << *max_element(d + 1, d + k + 1);
}
