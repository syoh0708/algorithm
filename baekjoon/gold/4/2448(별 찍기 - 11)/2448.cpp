#include <bits/stdc++.h>

using namespace std;

vector<string> base = {"  *  ", " * * ", "*****"};


vector<string> print_stars(int n, bool print) {
    if (n == 3) {
        if (print) {
            for (string str : base) {
                cout << str << '\n';
            }
            return {};
        } else {
            return base;
        }
    }

    vector<string> triangle = print_stars(n / 2, false);
    string padding = string(n / 2, ' ');

    if (print) {
        for (string str : triangle) {
            cout << padding << str << padding << '\n';
        }

        for (string str : triangle) {
            cout << str << ' ' << str << '\n';
        }

        return {};
    } else {
        vector<string> new_triangle = {};
        for (string str : triangle) {
            new_triangle.push_back(padding + str + padding);
        }
        
        for (string str : triangle) {
            new_triangle.push_back(str + ' ' + str);
        }

        return new_triangle;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;
    
    print_stars(n, true);
}
