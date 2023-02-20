#include <bits/stdc++.h>

using namespace std;

int f[405][5], board[25][25];
bool done[405];
pair<int, int> pos[405];
int ans, n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool is_friend_seaten(int idx) {
    for (int i = 1; i < 5; i++) {
        if (done[f[idx][i]]) return true;
    }

    return false;
}

pair<int, int> get_neighbor_score(int idx, int r, int c) {
    int empty_neighbor = 0, friend_neighbor = 0;

    for (int dir = 0; dir < 4; dir++) {
        int nx = r + dx[dir];
        int ny = c + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (!board[nx][ny]) {
            empty_neighbor++;
        } else {
            for (int i = 1; i < 5; i++) {
                if (f[idx][i] == board[nx][ny]) friend_neighbor++;
            }
        }
    }

    return {friend_neighbor, empty_neighbor};
}

pair<int, int> get_best_empty_seat() {
    int r = -1, c = -1, max_empty_neighbor = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) continue;

            int empty_neighbor = 0;
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (!board[nx][ny]) empty_neighbor++;
            }
            
            if (empty_neighbor > max_empty_neighbor) {
                if (empty_neighbor == 4) {
                    return {i, j};
                }

                r = i;
                c = j;
                max_empty_neighbor = empty_neighbor;
            }
        }
    }

    return {r, c};
}

pair<int, int> get_best_seat(int idx) {
    pair<int, int> max_score = {-1, -1};
    pair<int, int> seat = {n, n};

    for (int i = 1; i < 5; i++) {
        int frnd = f[idx][i];
        if (!done[frnd]) continue;

        pair<int, int> position = pos[frnd];

        for (int dir = 0; dir < 4; dir++) {
            int nx = position.first + dx[dir];
            int ny = position.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny]) continue;

            pair<int, int> score = get_neighbor_score(idx, nx, ny);
            pair<int, int> pos = {nx, ny};
            if (score > max_score) {
                max_score = score;
                seat = pos;
            } else if (score == max_score && pos < seat) {
                seat = pos;
            }
        }
    }

    if (seat == make_pair(n, n)) {
        seat = get_best_empty_seat();
    }

    return seat;
}

int satisfaction(int i) {
    int friend_cnt = 0;
    pair<int, int> position = pos[f[i][0]];
    
    for (int dir = 0; dir < 4; dir++) {
        int nx = position.first + dx[dir];
        int ny = position.second + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        int s = board[nx][ny];

        for (int j = 1; j < 5; j++) {
            if (s == f[i][j]) friend_cnt++;
        }
    }

    if (friend_cnt) return pow(10, friend_cnt - 1);
    else return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int s_cnt = n * n;

    for (int i = 0; i < s_cnt; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> f[i][j];
        }
    }

    for (int i = 0; i < s_cnt; i++) {
        int student = f[i][0];
        pair<int, int> seat;
        if (is_friend_seaten(i)) {
            seat = get_best_seat(i);
        } else {
            seat = get_best_empty_seat();
        }
        board[seat.first][seat.second] = student;
        done[student] = true;
        pos[student] = seat;
    }

    for (int i = 0; i < s_cnt; i++) {
        ans += satisfaction(i);
    }

    cout << ans;
}
