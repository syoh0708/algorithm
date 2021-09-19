#include<iostream>
#include<algorithm>

using namespace std;

int arr[16];

int main(void) {
    int n;

    cin >> n;

    if (n % 2) {
        cout << 0 << '\n';
        return 0;
    } 

    n /= 2;

    arr[1] = 3;
    arr[2] = 11;

    for (int i = 3; i <= n; i++) {
        arr[i] = 3 * arr[i - 1];
        for (int j = 2; j < i; j++) {
            arr[i] += 2 * arr[i - j];
        }
    }

    cout << arr[n] << '\n';    
 
    return 0;
}