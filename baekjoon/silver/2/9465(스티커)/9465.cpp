#include <iostream>
#include <algorithm>

using namespace std;
int max_score[100001][3], stickers[2][100001];

int main(void) {

    int t;

    cin >> t;

    while (t--) {
        int n;

        cin >> n;

        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> stickers[i][j];
            }
        }

        max_score[1][1] = stickers[0][1];
        max_score[1][2] = stickers[1][1];

        for (int i = 2; i <= n; i++) {
            max_score[i][0] = *max_element(max_score[i - 1], max_score[i - 1] + 3);
            max_score[i][1] = stickers[0][i] + max(max_score[i - 1][0], max_score[i - 1][2]);
            max_score[i][2] = stickers[1][i] + max(max_score[i - 1][0], max_score[i - 1][1]);
        }

        cout << *max_element(max_score[n], max_score[n] + 3) << '\n';
    }


    return 0;
}