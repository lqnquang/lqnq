#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int formingMagicSquare(vector< vector<int> > s);

int main() {
    vector< vector<int> > s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);
        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }
    }
    cout << formingMagicSquare(s);
}

int formingMagicSquare(vector< vector<int> > s) {
    int check[8][3][3] = {
        {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
        {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
        {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
        {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
        {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
        {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
        {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
        {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}
    };
    vector< int > arrcost;
    for (int k = 0; k < 8; k++) {
        int cost = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (s[i][j] != check[k][i][j]) {
                    cost += abs(s[i][j] - check[k][i][j]);
                }
            }
        }
        arrcost.push_back(cost);
    }
    int mincost = 100;
    for (int i = 0; i < arrcost.size(); i++) {
        mincost = min(mincost, arrcost[i]);
    }
    return mincost;
}