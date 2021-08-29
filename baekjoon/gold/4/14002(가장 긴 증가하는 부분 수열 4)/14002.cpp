#include <iostream>
#include <stack>

using namespace std;


int main(void) {
    stack<int> s;
    int n, last_index = 0, ans = 0, arr[1000], longest_array_ends_at[1000], before_index[1000];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        longest_array_ends_at[i] = 1;
        before_index[i] = -1;

        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && longest_array_ends_at[j] >= longest_array_ends_at[i]) {
                longest_array_ends_at[i] = longest_array_ends_at[j] + 1;
                before_index[i] = j;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (longest_array_ends_at[i] > ans) {
            ans = longest_array_ends_at[i];
            last_index = i;
        }
    }

    while (last_index != -1) {
        s.push(arr[last_index]);
        last_index = before_index[last_index];
    }

    cout << ans << '\n';

    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
}