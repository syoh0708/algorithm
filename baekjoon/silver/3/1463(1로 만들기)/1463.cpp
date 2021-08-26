#include <iostream>

using namespace std;

int arr[1000005] = {0, 0};

int main(void) {
    int n;

    cin >> n;

    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + 1;
        
        if (i % 2 == 0 && arr[i / 2] < arr[i]) {
            arr[i] = arr[i / 2] + 1;
        }

        if (i % 3 == 0 && arr[i / 3] < arr[i]) {
            arr[i] = arr[i / 3] + 1;
        }
    }

    cout << arr[n];

    return 0;
}