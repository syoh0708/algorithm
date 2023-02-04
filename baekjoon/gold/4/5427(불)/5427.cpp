#include <bits/stdc++.h>

using namespace std;

char arr[1001][1001];
int fire[1001][1001];
int dist[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, w, h;

    cin >> t;

    while (t--)
    {
        cin >> w >> h;

        queue<pair<int, int>> fq, sq;

        for (int i = 0; i < h; i++) {
            fill(fire[i], fire[i] + w, -1);
            fill(dist[i], dist[i] + w, -1);
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> arr[i][j];

                if (arr[i][j] == '@') {
                    sq.push({i, j});
                    dist[i][j] = 0;
                } else if (arr[i][j] == '*') {
                    fq.push({i, j});
                    fire[i][j] = 0;
                }
            }
        }

        int d = 0;
        bool possible = false;
        
        while (!sq.empty()) {
            while (!fq.empty()) {
                pair<int, int> fc = fq.front();
                if (fire[fc.first][fc.second] != d) break;

                fq.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = fc.first + dx[dir];
                    int ny = fc.second + dy[dir];

                    if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                    if (fire[nx][ny] == -1 && arr[nx][ny] != '#') {
                        fire[nx][ny] = d + 1;
                        fq.push({nx, ny});
                    }
                }
            }

            while (!sq.empty()) {
                pair<int, int> sc = sq.front();
                if (dist[sc.first][sc.second] != d) {
                    d++;
                    break;
                }

                sq.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = sc.first + dx[dir];
                    int ny = sc.second + dy[dir];

                    if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                        possible = true;
                        d++;
                        break;
                    }
                    if (dist[nx][ny] == -1 && arr[nx][ny] != '#' && fire[nx][ny] == -1) {
                        dist[nx][ny] = d + 1;
                        sq.push({nx, ny});
                    }
                }

                if (possible) {
                    while (!sq.empty()) {
                        sq.pop();
                    }

                    break;
                }
            }
        }
        
        if (possible) {
            cout << d << '\n';
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
}
