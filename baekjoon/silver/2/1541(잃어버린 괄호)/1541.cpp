#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s; cin >> s;

    int ans, tmp, cur = 0, nxt = 0, sz = s.size();
    bool minus_exist = false;
    vector<int> operands;
    vector<char> operators;

    while (nxt < sz) {
        while (nxt < sz && isdigit(s[nxt])) nxt++;
        tmp = stoi(s.substr(cur, nxt - cur));
        
        operands.push_back(tmp);
        if (nxt == sz) break;

        operators.push_back(s[nxt++]);
        cur = nxt;
    }

    ans = operands[0];

    for (int i = 0; i < operators.size(); i++) {
        if (minus_exist) {
            ans -= operands[i + 1];
        } else if (operators[i] == '+') {
            ans += operands[i + 1];
        } else {
            ans -= operands[i + 1];
            minus_exist = true;
        }
    }

    cout << ans;
}
