#include<iostream>
#include<algorithm>

using namespace std;

char candy[50][50];

int get_max_candy(char candy[][50], int n) {
    int max_candy = 1, current_length = 0;
    char current;

    for (int i = 0; i < n; i++) {
        current = '\0';

        for (int j = 0; j < n; j++) {
            if (current != candy[i][j]) {
                current = candy[i][j];
                current_length = 1;
            } else {
                current_length++;
                max_candy = current_length > max_candy ? current_length : max_candy;
            }
        }
    }

    for (int j = 0; j < n; j++) {
        current = '\0';

        for (int i = 0; i < n; i++) {
            if (current != candy[i][j]) {
                current = candy[i][j];
                current_length = 1;
            } else {
                current_length++;
                max_candy = current_length > max_candy ? current_length : max_candy;
            }
        }
    }

    return max_candy;
}

void swap_candy(char candy[][50], int i, int j, bool horizontal) {
    char temp;

    if (horizontal) {
        temp = candy[i][j];
        candy[i][j] = candy[i][j + 1];
        candy[i][j + 1] = temp;    
    } else {
        temp = candy[i][j];
        candy[i][j] = candy[i + 1][j];
        candy[i + 1][j] = temp;    
    }

    return;
}

int main(void) {
    int n, ans = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
                cin >> candy[i][j];
        }
    }

    ans = max(ans, get_max_candy(candy, n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            swap_candy(candy, i, j, true);
            ans = max(ans, get_max_candy(candy, n));
            swap_candy(candy, i, j, true);
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - 1; i++) {
            swap_candy(candy, i, j, false);
            ans = max(ans, get_max_candy(candy, n));
            swap_candy(candy, i, j, false);
        }
    }

    cout << ans << '\n';

    return 0;
}