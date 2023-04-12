#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000'000;
int n, m, s, e, ans;
vector<pair<int, int>> adj[200005];
int d[200005];
int pre[200005];
vector<bool> vis(200005);
priority_queue<
    tuple<int, int, int>,
    vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>>
> q1, q2;

bool lex_prev(int u, int v) {
    stack<int> us, vs;

    int cur = u;
    us.push(cur);
    while (cur) {
        us.push(pre[cur]);
        cur = pre[cur];
    }

    cur = v;
    vs.push(v);
    while (cur) {
        vs.push(pre[cur]);
        cur = pre[cur];
    }

    while (!us.empty() && !vs.empty()) {
        if (us.top() != vs.top()) return us.top() < vs.top();

        us.pop();
        vs.pop();
    }

    return true;
}

pair<int, int> min_path(vector<pair<int, int>>& cand) {
    pair<int, int> v = cand[0];
    int sz = cand.size();

    for (int i = 1; i < sz; i++)
        if (lex_prev(cand[i].first, v.first)) v = cand[i];

    return v;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        
        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }

    cin >> s >> e;

    fill(d + 1, d + n + 1, MAX);

    d[s] = 0;
    vis[s] = true;
    for (auto edge : adj[s]) q1.emplace(edge.first, edge.second, s);

    while (!vis[e]) {
        int w, v, u;

        tie(w, v, u) = q1.top(); q1.pop();

        if (w > d[e]) break;
        if (w < d[v]) {
            vector<pair<int, int>> cand;

            while (!q1.empty()) {
                int nw, nv, nu;

                tie(nw, nv, nu) = q1.top();


                if (nw > w || nv > v) break;

                cand.emplace_back(nu, nv);
                q1.pop();
            }

            if (cand.size()) {
                cand.emplace_back(u, v);
                tie(u, v) = min_path(cand);
            }

            vis[v] = true;
            d[v] = w;
            pre[v] = u;
            for (auto edge : adj[v]) {
                if (!vis[edge.second]) q1.emplace(d[v] + edge.first, edge.second, v);
            }
        }
    }


    ans += d[e];
    int cur = e;

    while (pre[cur]) {
        if (pre[pre[cur]]) adj[pre[cur]].clear();
        
        cur = pre[cur];
    }

    fill(d + 1, d + n + 1, MAX);
    fill(pre + 1, pre + n + 1, 0);
    fill(vis.begin() + 1, vis.begin() + n + 1, false);
    d[e] = 0;
    vis[e] = true;

    for (auto edge : adj[e]) q2.emplace(edge.first, edge.second, e);

    while (!vis[s]) {
        int w, v, u;

        tie(w, v, u) = q2.top(); q2.pop();

        if (w < d[v]) {
            vector<pair<int, int>> cand;

            while (!q2.empty()) {
                int nw, nv, nu;

                tie(nw, nv, nu) = q2.top();


                if (nw > w || nv > v) break;

                cand.emplace_back(nu, nv);
                q2.pop();
            }

            if (cand.size()) {
                cand.emplace_back(u, v);

                tie(u, v) = min_path(cand);
            }

            vis[v] = true;

            d[v] = w;
            pre[v] = u;
            for (auto edge : adj[v]) {
                if (!vis[edge.second]) q2.emplace(d[v] + edge.first, edge.second, v);
            }
        }
    }

    ans += d[s];

    cout << ans;
}
