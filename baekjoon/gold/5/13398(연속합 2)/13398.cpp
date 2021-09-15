#include<iostream>
#include<algorithm>

using namespace std;

int arr[100000], ml[100000], mr[100000];

int main(void) {
    int n, ans;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ml[0] = arr[0];
    mr[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++) {
        ml[i] = max(ml[i - 1] + arr[i], arr[i]);
        mr[n - 1 - i] = max(mr[n - i] + arr[n - 1 - i], arr[n - 1 - i]);
    }

    ans = *max_element(ml, ml + n);
    for (int i = 1; i < n - 1; i++) {
        if (ml[i - 1] + mr[i + 1] > ans) {
            ans = ml[i - 1] + mr[i + 1];
        }
    }

    cout << ans << '\n';

    return 0;
}