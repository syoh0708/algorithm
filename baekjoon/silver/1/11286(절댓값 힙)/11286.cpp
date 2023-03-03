#include <bits/stdc++.h>

using namespace std;

class cmp {
public:
    bool operator() (int a, int b) {
        if (abs(a) != abs(b)) return abs(a) > abs(b);

        return a > b;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<int, vector<int>, cmp> q;

    int n; cin >> n;

    while (n--) {
        int x; cin >> x;

        if (x) {
            q.push(x);
        } else {
            if (q.empty()) cout << "0\n";
            else {
                cout << q.top() << '\n'; 
                q.pop();
            }
        }
    }
}
