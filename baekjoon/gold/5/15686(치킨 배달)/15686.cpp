#include <bits/stdc++.h>

using namespace std;

int distances[200][13];
int min_distance = 100000000;
int c_count, h_count;

int dist(pair<int, int>& a, pair<int, int>& b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void fill_distances(vector<pair<int, int>>& h, vector<pair<int, int>>& c) {
    for (int i = 0; i < h_count; i++) {
        for (int j = 0; j < c_count; j++) {
            distances[i][j] = dist(h[i], c[j]);
        }
    }
}

int calculate_chicken_distance(vector<bool>& cidx) {
    int chicken_distance = 0;

    for (int i = 0; i < h_count; i++) {
        int min_distance = 1000;
        
        for (int j = 0; j < c_count; j++) {
            if (cidx[j]) min_distance = min(min_distance, distances[i][j]);
        }

        chicken_distance += min_distance;
    }

    return chicken_distance;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a;
    cin >> n >> m;

    vector<pair<int, int>> h;
    vector<pair<int, int>> c;
    vector<bool> cidx = {};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            if (a == 2) {
                c.push_back({i, j});
            } else if (a == 1) {
                h.push_back({i, j});
            }
        }
    }
    c_count = c.size();
    h_count = h.size();

    fill_distances(h, c);

    for (int i = 0; i < c_count - m; i++) cidx.push_back(false);
    for (int i = c_count - m; i < c_count; i++) cidx.push_back(true);

    do {
        min_distance = min(min_distance, calculate_chicken_distance(cidx));
    } while (next_permutation(cidx.begin(), cidx.end()));

    cout << min_distance;
}
