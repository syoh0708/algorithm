#include <bits/stdc++.h>

using namespace std;

int sushi[30000];
int eat[3001];
int n, d, k, c, max_cnt = 0, cnt = 1;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> d >> k >> c;

    for (int i = 0; i < n; i++) {
        cin >> sushi[i];
    }

    eat[c] = 50000;

    for (int i = 0; i < k; i++) {
        if (!eat[sushi[i]]) cnt++;
        eat[sushi[i]]++;
    }
    max_cnt = max(max_cnt, cnt);

    int cur = 1;
    while (cur < n) {
        eat[sushi[cur - 1]]--;
        if (!eat[sushi[cur - 1]]) cnt--;
        if (!eat[sushi[(cur + k - 1) % n]]) cnt++;
        eat[sushi[(cur + k - 1) % n]]++;

        max_cnt = max(max_cnt, cnt);
        cur++;
    }

    cout << max_cnt;
}
