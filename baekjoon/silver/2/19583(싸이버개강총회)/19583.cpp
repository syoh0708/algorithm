#include <bits/stdc++.h>

using namespace std;

int parse_time(string time) {
    return stoi(time.substr(0,2)) * 60 + stoi(time.substr(3,2));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s, e, q;
    unordered_set<string> us;
    unordered_set<string> ans;

    cin >> s >> e >> q;

    int start = parse_time(s);
    int end = parse_time(e);
    int quit = parse_time(q);

    while (1) {
        string t, name;

        cin >> t >> name;

        if (cin.eof()) break;

        int time = parse_time(t);

        if (time <= start) {
            us.insert(name);
        } else if (time >= end && time <= quit) {
            if (us.find(name) != us.end()) {
                ans.insert(name);
            }
        }
    }

    cout << ans.size();
}
