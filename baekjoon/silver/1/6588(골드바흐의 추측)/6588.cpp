#include <iostream>
#include <utility>
#include <stack>

using namespace std;
const int MAX = 1000005;
bool composite[MAX] = {true, true};
int prime[MAX];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int pi = 0, n;

    for (int i = 2; i < 1000000; i++) {
        if (composite[i]) {
            continue;
        }
        
        prime[pi++] = i;
        
        for (int j = i * i; i < 1000 && j < 1000000; j += i) {
            composite[j] = true;
        }
    }

    while (true) {
        cin >> n;

        if (n == 0) {
            break;
        }

        for (int i = 0; i < pi; i++) {
            if (!composite[n - prime[i]]) {
                cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
                break;
            }
        }
    }
    
    return 0;
}
