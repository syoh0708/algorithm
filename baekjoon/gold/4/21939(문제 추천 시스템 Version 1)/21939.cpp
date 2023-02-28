#include<bits/stdc++.h>

using namespace std;


set<int> difficulty[101];
int problem[100'000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    

    cin >> n;

    while (n--) {
        int p, l;

        cin >> p >> l;
        difficulty[l].insert(p);
        problem[p] = l;
    }

    cin >> m;

    while (m--) {
        string op; cin >> op;

        if (op == "add") {
            int p, l; cin >> p >> l;

            difficulty[l].insert(p);
            problem[p] = l;
        } else if (op == "recommend") {
            int x; cin >> x;

            if (x == 1) {
                for (int i = 100; i >= 0; i--) {
                    if (difficulty[i].empty()) continue;

                    cout << *(prev(difficulty[i].end())) << '\n';
                    break;
                }
            } else {
                for (int i = 0; i < 101; i++) {
                    if (difficulty[i].empty()) continue;

                    cout << *(difficulty[i].begin()) << '\n';
                    break;
                }
            }
        } else {
            int p; cin >> p;

            int cur_difficulty = problem[p];

            problem[p] = 0;
            difficulty[cur_difficulty].erase(p);
        }
    }
}
