#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000'000;
int n, k;
int dist[200005];
deque<int> dq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    fill(dist, dist + 200005, MAX);
    dq.push_back(n);
    dist[n] = 0;

    while (!dq.empty()) {
        int cur = dq.front(); dq.pop_front();
        int nxt = cur;
        while (nxt <= 100000) {
            nxt *= 2;
            
            if (dist[nxt] <= dist[cur]) break;
                
            dist[nxt] = dist[cur];
            dq.push_front(nxt);
        }

        nxt = cur + 1;
        if (nxt <= 200000 && dist[cur] + 1 < dist[nxt]) {
            dist[nxt] = dist[cur] + 1;
            dq.push_back(nxt);
        }

        nxt = cur - 1;
        if (nxt >= 0 && dist[cur] + 1 < dist[nxt]) {
            dist[nxt] = dist[cur] + 1;
            dq.push_back(nxt);
        }
    }

    cout << dist[k];
}
