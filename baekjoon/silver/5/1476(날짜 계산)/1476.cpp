#include<iostream>

using namespace std;
int E = 15, S = 28, M = 19;

int main(void) {
    int e, s, m;

    cin >> e >> s >> m;

    cout << ((e * S * M * 13 + s * E * M * 17 + m * E * S * 10 - 1) % (E * S * M)) + 1 << '\n';

    return 0;
}