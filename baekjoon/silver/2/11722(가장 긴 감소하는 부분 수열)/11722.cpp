#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000], max_desc[1000];

int main(void) {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        max_desc[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] < arr[j] && max_desc[i] < max_desc[j] + 1) {
                max_desc[i] = max_desc[j] + 1;
            }
        }
    }

    cout << *max_element(max_desc, max_desc + n);

    return 0;
}