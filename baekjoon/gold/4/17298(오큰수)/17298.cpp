#include <iostream>
#include <utility>
#include <stack>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<pair<int, int>> s;
    int arr[1000000];
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (s.empty() || s.top().second >= a) {
            s.push(make_pair(i, a));
        } else {
            while (!s.empty() && s.top().second < a) {
                arr[s.top().first] = a;
                s.pop();
            }

            s.push(make_pair(i, a));
        }
    }

    while (!s.empty()) {
        arr[s.top().first] = -1;
        s.pop();
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }

    cout << '\n';

    return 0;
}