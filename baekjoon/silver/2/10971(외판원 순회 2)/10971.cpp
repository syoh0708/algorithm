#include<iostream>
#include<algorithm>

using namespace std;

int cost[11][11];
bool used[11];
int min_cost[11];

int min(int a, int b) {
    return a < b ? a : b;
}

int get_min_cost(int src, int dest, int city_count, int len) {
    if (len == 1) {
        return cost[src][dest];
    }

    int min_cost = 10000000;

    for (int i = 0; i < city_count; i++) {
        if (used[i] || i == src || cost[src][i] == 0 || (len > 0 && i == dest)) continue;

        used[i] = true;
        int next_min_cost = get_min_cost(i, dest, city_count, len - 1);
        if (next_min_cost == 0) return 10000000;

        min_cost = min(min_cost, cost[src][i] + next_min_cost);
        used[i] = false;
    }
    
    return min_cost;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        min_cost[i] = get_min_cost(i, i, n, n);
    }

    cout << *min_element(min_cost, min_cost + n) << '\n';

    return 0;
}
