#include <bits/stdc++.h>

using namespace std;

vector<string> recursion = {
    "\"재귀함수가 뭔가요?\"",
    "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.",
    "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.",
    "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\""
};
string ans = "라고 답변하였지.";

vector<string> base = {
    "\"재귀함수가 뭔가요?\"",
    "\"재귀함수는 자기 자신을 호출하는 함수라네\"",
    "라고 답변하였지."
};

vector<string> func(int n, string prefix) {
    if (n == 0) {
        vector<string> ret;

        for (string str : base) ret.push_back(prefix + str);

        return ret;
    }

    vector<string> ret;

    for (string str : recursion) ret.push_back(prefix + str);
    for (string str : func(n - 1, prefix +  "____")) ret.push_back(str);
    ret.push_back(prefix + ans);

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;

    cin >> n;

    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    for (string str : func(n, "")) cout << str << '\n';
}
