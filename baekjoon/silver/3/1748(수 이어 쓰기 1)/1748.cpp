#include<iostream>

using namespace std;

int main(void) {
    int n, m, digit = 0, power_of_ten = 1, ans = 0;
    
    cin >> n;

    m = n;
    while (m) {
        m /= 10;
        digit++;
    }

    for (int i = 1; i < digit; i++) {
        ans += i * power_of_ten * 9;
        power_of_ten *= 10;
    }

    ans += digit * (n + 1 - power_of_ten);
    
    cout << ans;

    return 0;
}