#include <bits/stdc++.h>

using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수

void push(int x){
    int cur = ++sz;
    int parent = cur / 2;
    heap[cur] = x;

    while (parent > 0 && heap[cur] < heap[parent]) {
        swap(heap[cur], heap[parent]);
        cur = parent;
        parent = cur / 2;
    }
}

int top(){
    if (sz == 0) return 0;
    return heap[1];
}

void pop(){
    if (sz == 0) return;

    heap[1] = heap[sz--];
    int cur = 1;
    int lc = cur * 2;
    int rc = cur * 2 + 1;
    while ((lc <= sz && heap[cur] > heap[lc]) || (rc <= sz && heap[cur] > heap[rc])) {
        if (rc <= sz && heap[rc] < heap[lc]) {
            swap(heap[rc], heap[cur]);
            cur = rc;
        } else {
            swap(heap[lc], heap[cur]);
            cur = lc;
        }
        lc = cur * 2;
        rc = cur * 2 + 1;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;

    while (n--) {
        int x; cin >> x;

        if (x) {
            push(x);
        } else {
            cout << top() << '\n'; pop();
        }
    }
}
