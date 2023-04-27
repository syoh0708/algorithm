#include <bits/stdc++.h>

using namespace std;

int n, l, ans;
int b[105][105];

bool solve(vector<int>& v) {
    bool vis[105] = {};

    int st = v[0];
    int i = 0;
    while (i < n) {
        if (v[i] >= st) {
            st = v[i];
            i++;
            continue;
        }
        else if (v[i] < st - 1) return false;

        int cnt = 1;
        st = v[i];
        vis[i++] = true;

        while (cnt < l) {
            if (i >= n) return false;
            if (v[i - 1] != v[i]) return false;
            vis[i++] = true;
            cnt++;
        }
    }

    st = v[n - 1];
    i = n - 1;
    while (i >= 0) {
        if (v[i] >= st) {
            st = v[i];
            i--;
            continue;
        }

        else if (v[i] < st - 1) return false;

        int cnt = 1;
        st = v[i];
        if (vis[i]) return false;
        vis[i--] = true;

        while (cnt < l) {
            if (i < 0) return false;
            if (v[i + 1] != v[i]) return false;
            if (vis[i]) return false;
            vis[i--] = true;
            cnt++;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin >> b[i][j];

    

    for (int i = 0; i < n; i++) {
        vector<int> v1, v2;

        for (int j = 0; j < n; j++){
            v1.push_back(b[i][j]);
            v2.push_back(b[j][i]);
        }

        ans += solve(v1);
        ans += solve(v2);
    }

    cout << ans;
}
