#include <bits/stdc++.h>

using namespace std;

int board[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, k, l, x, i, j, cx, cy, dir, idx, t;
char c;
vector<pair<int, char>> v;
queue<pair<int, int>> q;

int mod(int a, int m) {
    return (a % m + m) % m;
}

bool step() {
    t++;

    cx += dx[dir];
    cy += dy[dir];

    if (cx < 0 || cx >= n || cy < 0 || cy >= n || board[cx][cy] == 1) {
        return false;
    }
    if (board[cx][cy] == 0) {
        pair<int, int> tail = q.front(); q.pop();
        board[tail.first][tail.second] = 0;
    } 

    board[cx][cy] = 1;
    q.push({cx, cy});


    if (idx < v.size() && v[idx].first == t) {
        if (v[idx].second == 'D') {
            dir = mod(dir + 1, 4);
        } else {
            dir = mod(dir - 1, 4);
        }
        idx++;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    while (k--) {
        cin >> i >> j;

        board[i - 1][j - 1] = 2;
    }
    board[0][0] = 1;
    q.push({0, 0});

    cin >> l;

    while (l--) {
        cin >> x >> c;

        v.push_back({x, c});
    }

    while (step()) {}

    cout << t;
}
