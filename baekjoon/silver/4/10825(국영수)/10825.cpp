#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<tuple<int, int, int, string>> v;
    int n, kor, eng, math;
    string name;

    cin >> n;

    while (n--) {
        cin >> name >> kor >> eng >> math;
        v.push_back({-kor, eng, -math, name});
    }

    sort(v.begin(), v.end());

    for (auto t : v) {
        cout << get<3>(t) << '\n';
    }
}
