#include<iostream>
#include<cmath>
using namespace std;
 
int main(void)
{   
    int n;
    double x, y;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        cout << floor(2 * sqrt(y - x - 3.0 / 4)) << endl;
    }

    return 0;
}