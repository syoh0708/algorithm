#include<iostream>

using namespace std;
 
int d(int n)
{
    int result = n;

    do {
        result += n % 10;
        n /= 10;
    } while (n);

    return result;
}

int main(void)
{   
    bool not_self_numbers[10001] = { false };

    for (int i = 1; i <= 10000; i++) {
        int res = d(i);
        if (res <= 10000) {
            not_self_numbers[res] = true;
        }
        if (!not_self_numbers[i]) {
            cout << i << endl;
        }
    }

    return 0;
}
