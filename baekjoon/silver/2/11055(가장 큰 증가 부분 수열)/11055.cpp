#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000], sum[1000];

int main(void) {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && sum[j] > sum[i]) {
                sum[i] = sum[j];
            }
        }

        sum[i] += arr[i];
    }

    cout << *max_element(sum, sum + n) << '\n';
    
    return 0;
}