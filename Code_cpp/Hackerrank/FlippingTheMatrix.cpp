#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const int a, const int b) {
    return a > b;
}

int result(vector < vector < int > > matrix) {
    int maxS = 0, tmp;
    int len = matrix.size() - 1;
    
        for (int i = 0; i <= len / 2; i++) {
            for (int j = 0; j <= len / 2; j++) {
                tmp = max(matrix[i][j], max(matrix[len - i][len - j], 
                        max(matrix[len - i][j], matrix[i][len - j])));
                maxS += tmp;
            }
        }
    return maxS;
}

int main() {
    int n;
    cin >> n;
    vector < vector < int > > matrix(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        matrix[i].resize(2 * n);
        for (int j = 0; j < 2 * n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << result(matrix);
    return 0;
}