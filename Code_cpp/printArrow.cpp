#include <iostream>
#include <cmath>
using namespace std;

void printArrow(int n, bool left);

int main() {
    int n;
    cin >> n;
    bool t;
    cin >> t;
    printArrow(n, t);
}

void printArrow(int n, bool left) {
    int t = n;
    if (left == 0) {
        int space = 0;
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= space; k++)
                cout << " ";
            for (int j = 1; j <= t; j++)       
                cout << "*";
            cout << endl;
            space += 2;
            t -= 1;
        }
        space -= 2;
        t += 1;
        for (int i = 1; i <= n - 1; i++) {
            space -= 2;
            t += 1;
            for (int k = 1; k <= space; k++)
                cout << " ";
            for (int j = 1; j <= t; j++)
                cout << "*";
            cout << endl;
        }
    } else {
        int space = t - 1;
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= space; k++)
                cout << " ";
            for (int j = 1; j <= t; j++)       
                cout << "*";
            cout << endl;
            space -= 1;
            t -= 1;
        }
        space += 1;
        t += 1;
        for (int i = 1; i <= n - 1; i++) {
            space += 1;
            t += 1;
            for (int k = 1; k <= space; k++)
                cout << " ";
            for (int j = 1; j <= t; j++)
                cout << "*";
            cout << endl;
        }
    }
}
