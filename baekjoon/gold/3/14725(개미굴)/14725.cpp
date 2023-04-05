#include <bits/stdc++.h>

using namespace std;

const int ROOT = 1;
const int MAX = 15 * 1000 + 5;
int unused = 2;
map<string, int> nxt[MAX];
int n;

void insert(vector<string> feeds) {
    int cur = ROOT;

    for (string feed : feeds) {
        if (nxt[cur][feed] == 0) nxt[cur][feed] = unused++;

        cur = nxt[cur][feed];
    }
}

void print_feeds(int cur, string prefix) {
    for (auto feed : nxt[cur]) {
        cout << prefix << feed.first << '\n';
        print_feeds(feed.second, "--" + prefix);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--) {
        int m; cin >> m;
        vector<string> feeds;
        
        while (m--) {
            string feed; cin >> feed;

            feeds.push_back(feed);
        }

        insert(feeds);
    }

    print_feeds(ROOT, "");
}
