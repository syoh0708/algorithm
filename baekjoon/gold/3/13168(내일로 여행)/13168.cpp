#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000'000;
int n, m, r, k;
int trvl[205];
int adj_yes[105][105];
int adj_no[105][105];
string city[105];
unordered_map<string, int> city_map;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r;

    int idx = 1, nn = n;
    while (nn--) {
        string s; cin >> s;

        if (city_map.find(s) != city_map.end()) continue;
        
        city_map[s] = idx;
        city[idx++] = s;
    }

    n = idx;

    for (int i = 1; i <= n; i++) {
        fill(adj_yes[i] + 1, adj_yes[i] + n + 1, MAX);
        fill(adj_no[i] + 1, adj_no[i] + n + 1, MAX);
        adj_yes[i][i] = 0;
        adj_no[i][i] = 0;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        trvl[i] = city_map[s];
    }

    cin >> k;

    while (k--) {
        string type, origin, dest;
        int price;

        cin >> type >> origin >> dest >> price;
        int i = city_map[origin];
        int j = city_map[dest];

        if (type == "Mugunghwa" || type == "ITX-Saemaeul" || type == "ITX-Cheongchun") {
            adj_yes[i][j] = 0;
        } else if (type == "S-Train" || type == "V-Train") {
            adj_yes[i][j] = min(adj_yes[i][j], price);
        } else {
            adj_yes[i][j] = min(adj_yes[i][j], price * 2);
        }

        adj_no[i][j] = min(adj_no[i][j], price * 2);
        adj_yes[j][i] = adj_yes[i][j];
        adj_no[j][i] = adj_no[i][j];
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                adj_yes[i][j] = min(adj_yes[i][j], adj_yes[i][k] + adj_yes[k][j]);
                adj_no[i][j] = min(adj_no[i][j], adj_no[i][k] + adj_no[k][j]);
            }
        }
    }

    long long price_yes = r * 2, price_no = 0;

    for (int i = 1; i < m; i++) {
        price_yes += adj_yes[trvl[i - 1]][trvl[i]];
        price_no += adj_no[trvl[i - 1]][trvl[i]];
    }

    cout << (price_yes < price_no ? "Yes" : "No");
}
