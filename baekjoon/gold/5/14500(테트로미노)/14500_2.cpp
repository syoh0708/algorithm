#include<iostream>

using namespace std;

int table[500][500];

int main(void) {
    int n, m, sum_max = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum_candy = table[i][j];
            for (int k = 0; k < 3; k++) {
                
            }
        }
    }

    return 0;
}