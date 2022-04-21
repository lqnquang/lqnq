#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, q, k;
    cin >> n >> q;
    vector < vector < int > > matrix;
    matrix.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> k;
        matrix[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> matrix[i][j];
        }
    }
    int index1, index2;
    for (int i = 0; i < q; i++) {
        cin >> index1 >> index2;
        cout << matrix[index1][index2] << endl;
    }
    return 0;
}