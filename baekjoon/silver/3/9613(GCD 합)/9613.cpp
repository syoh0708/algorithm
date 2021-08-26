#include<iostream>

using namespace std;

long long gcd(int n, int m) {
    if (m > n) {
        int tmp = n;
        n = m;
        m = tmp;
    }

    int r;

    while (m) {
        r = n % m;
        n = m;
        m = r;
    }

    return n;
}

int main(void) {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, arr[100];
        long long ans = 0;

        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += gcd(arr[i], arr[j]);
            }
        }

        cout << ans << '\n';
    }
    

    return 0;
}
