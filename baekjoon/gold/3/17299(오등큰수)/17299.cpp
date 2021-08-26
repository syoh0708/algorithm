#include <iostream>
#include <utility>
#include <stack>

using namespace std;
const int MAX = 1000005;
int n, arr[MAX], cnt[MAX], ans[MAX];

int main(void) {
    stack<int> s;

    scanf("%d",&n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        cnt[arr[i]]++;
    }
 
    for (int i = 0; i < n; i++) {
        while (!s.empty() && cnt[arr[i]] > cnt[arr[s.top()]]) {
            ans[s.top()] = arr[i];
            s.pop();
        }

        s.push(i);
    }

    while (!s.empty()) {
        ans[s.top()] = -1;
        s.pop();
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}
