#include<iostream>

using namespace std;

int arr[100005];

int gcd(int n, int m) {
    return n % m ? gcd(m, n % m) : m;
}

int main(void) {
    int n, s;

    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        arr[i] -= s;
    }

    int ans = arr[0];

    for (int i = 1; i < n; i++) {
        ans = gcd(ans, arr[i]);
    }

    printf("%d\n", ans > 0 ? ans : -ans);

    return 0;
}
