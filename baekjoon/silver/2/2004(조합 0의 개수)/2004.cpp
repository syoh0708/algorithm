#include <iostream>
#include <stack>

using namespace std;

long long power_count(long long n, int p) {
    long long cnt = 0;

    while (n) {
        n /= p;
        cnt += n;
    }

    return cnt;
}

int main(void) {
    int n, m;

    cin >> n >> m;

    int power_2 = power_count(n, 2) - power_count(m, 2) - power_count(n - m, 2);
    int power_5 = power_count(n, 5) - power_count(m, 5) - power_count(n - m, 5);

    cout << (power_2 > power_5 ? power_5 : power_2) << '\n';
}
