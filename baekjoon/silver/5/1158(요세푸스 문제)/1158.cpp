#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    queue<int> q;

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    cout << '<';

    while (true) {
        for (int i = 1; i < k; i++) {
            q.push(q.front());
            q.pop();
        }
        int c = q.front();

        q.pop();
        
        cout << c;
        if (q.empty()) {
            cout << ">\n";
            break;
        }

        cout << ", ";
    }

    return 0;
}