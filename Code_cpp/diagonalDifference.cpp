#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int diagonalDifference(vector< vector<int> >arr);
int main() {
    int n;
    cin >> n;
    vector< vector<int> >matrixx;
    matrixx.resize(n);
    for (int i = 0; i < n; i++) {
        matrixx[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> matrixx[i][j];
        }
    }
    cout << diagonalDifference(matrixx) << endl;
    return 0;
}
int diagonalDifference(vector< vector<int> >arr) {
    int sum_lr = 0, sum_rl = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            if (i == j)
                sum_lr += arr[i][j];
            if (i + j == arr.size() - 1)
                sum_rl += arr[i][j];
        }
    }
    return abs(sum_lr - sum_rl);
}
