#include <iostream>
#include <algorithm>

using namespace std;
int max_score[10001], wine[10001];

int main(void) {
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> wine[i];
    }

    max_score[1] = wine[1];
    if (n > 1) max_score[2] = wine[1] + wine[2];

    for (int i = 3; i <= n; i++) {
        max_score[i] = max(
            max(max_score[i - 1], max_score[i - 2] + wine[i]),
            max_score[i - 3] + wine[i - 1] + wine[i]
        );
    }

    cout << max_score[n];
}