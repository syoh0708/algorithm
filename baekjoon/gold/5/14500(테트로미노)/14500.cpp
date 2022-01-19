#include<iostream>

using namespace std;

int table[500][500], table_90[500][500], table_180[500][500], table_270[500][500];

int main(void) {
    int n, m, num, sum_max = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> num;
            table[i][j] = num;
            table_90[j][n - 1 - i] = num;
            table_180[n - 1 - i][m - 1 - j] = num;
            table_270[m - 1 - j][i] = num;
        }
    }
    // ㅁ
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            sum_max = max(sum_max, table[i][j] + table[i + 1][j] + table[i][j + 1] + table[i + 1][j + 1]);
        }
    }

    // ㅡ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 3; j++) {
            sum_max = max(sum_max, table[i][j] + table[i][j + 1] + table[i][j + 2] + table[i][j + 3]);
        }
    } 
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            sum_max = max(sum_max, table_90[j][i] + table_90[j][i + 1] + table_90[j][i + 2] + table_90[j][i + 3]);
        }
    }

    //ㅏ
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 1; j++) {
            sum_max = max(sum_max, table[i][j] + table[i + 1][j] + table[i + 1][j + 1] + table[i + 2][j]);
            sum_max = max(sum_max, table_180[i][j] + table_180[i + 1][j] + table_180[i + 1][j + 1] + table_180[i + 2][j]);
        }
    } 
    for (int j = 0; j < m - 2; j++) {
        for (int i = 0; i < n - 1; i++) {
            sum_max = max(sum_max, table_90[j][i] + table_90[j + 1][i] + table_90[j + 1][i + 1] + table_90[j + 2][i]);
            sum_max = max(sum_max, table_270[j][i] + table_270[j + 1][i] + table_270[j + 1][i + 1] + table_270[j + 2][i]);
        }
    }
            

    // ㄹ
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 1; j++) {
            sum_max = max(sum_max, table[i][j] + table[i + 1][j] + table[i + 1][j + 1] + table[i + 2][j + 1]);
            sum_max = max(sum_max, table[i][j + 1] + table[i + 1][j] + table[i + 1][j + 1] + table[i + 2][j]);
        }
    } 
    for (int j = 0; j < m - 2; j++) {
        for (int i = 0; i < n - 1; i++) {
            sum_max = max(sum_max, table_90[j][i] + table_90[j + 1][i] + table_90[j + 1][i + 1] + table_90[j + 2][i + 1]);
            sum_max = max(sum_max, table_90[j][i + 1] + table_90[j + 1][i] + table_90[j + 1][i + 1] + table_90[j + 2][i]);
        }
    }


    // ㄱ
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 1; j++) {
            sum_max = max(sum_max, table[i][j] + table[i + 1][j] + table[i + 2][j] + table[i + 2][j + 1]);
            sum_max = max(sum_max, table_180[i][j] + table_180[i + 1][j] + table_180[i + 2][j] + table_180[i + 2][j + 1]);
            sum_max = max(sum_max, table[i][j] + table[i + 1][j] + table[i + 2][j] + table[i][j + 1]);
            sum_max = max(sum_max, table_180[i][j] + table_180[i + 1][j] + table_180[i + 2][j] + table_180[i][j + 1]);
        }
    } 
    for (int j = 0; j < m - 2; j++) {
        for (int i = 0; i < n - 1; i++) {
            sum_max = max(sum_max, table_90[j][i] + table_90[j + 1][i] + table_90[j + 2][i] + table_90[j + 2][i + 1]);
            sum_max = max(sum_max, table_270[j][i] + table_270[j + 1][i] + table_270[j + 2][i] + table_270[j + 2][i + 1]);
            sum_max = max(sum_max, table_90[j][i] + table_90[j + 1][i] + table_90[j + 2][i] + table_90[j][i + 1]);
            sum_max = max(sum_max, table_270[j][i] + table_270[j + 1][i] + table_270[j + 2][i] + table_270[j][i + 1]);
        }   
    }


    cout << sum_max << '\n';
}