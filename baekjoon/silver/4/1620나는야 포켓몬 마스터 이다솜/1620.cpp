#include <bits/stdc++.h>

using namespace std;

string pokemon[100001];
unordered_map<string, int> dict;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> pokemon[i];
        dict[pokemon[i]] = i;
    }

    while (m--) {
        string quiz;

        cin >> quiz;

        if (quiz[0] >= '0' && quiz[0] <= '9') {
            int idx = stoi(quiz);

            cout << pokemon[idx] << '\n';
        } else {
            cout << dict[quiz] << '\n';
        }
    }
}
