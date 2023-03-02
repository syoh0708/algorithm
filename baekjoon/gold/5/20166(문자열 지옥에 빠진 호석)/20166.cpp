#include <bits/stdc++.h>

using namespace std;

string board[10];
unordered_map<string, int> dict;

int n, m, k;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int mod(int a, int b) {
    return (a % b + b) % b; 
}

void func(string s, int x, int y) {
    for (int dir = 0; dir < 8; dir++) {
        int nx = mod(x + dx[dir], n);
        int ny = mod(y + dy[dir], m);

        dict[s + board[nx][ny]]++;
        if (s.size() < 4) func(s + board[nx][ny], nx, ny);
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    string s = "";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            s = board[i][j];
            dict[s]++;

            func(s, i, j);
        }
    }

    while (k--) {
        string s;

        cin >> s;

        cout << dict[s] << '\n';
    }
}
