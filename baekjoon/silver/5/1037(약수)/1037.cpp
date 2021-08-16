#include<iostream>

using namespace std;
 
int main(void)
{   
    int n, max = INT32_MIN, min = INT32_MAX;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int aliquot;
        cin >> aliquot;
        max = aliquot > max ? aliquot : max;
        min = aliquot < min ? aliquot : min;
    }

    cout << max * min << endl;

    return 0;
}