#include <iostream>
#include <vector>

using namespace std;

void climbingLeaderboard(vector< int > ranked, vector< int > player);

int main() {
    int n, m;
    cin >> n;
    vector< int > ranked(n);
    for (int i = 0; i < n; i++) {
        cin >> ranked[i];
    }
    cin >> m;
    vector< int > player(m);
    for (int i = 0; i < m; i++) {
        cin >> player[i];
    }
    /*vector< int > result =*/ climbingLeaderboard(ranked, player);
    /*for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }*/
}

void climbingLeaderboard(vector< int > ranked, vector< int > player) {
    vector< int > result(player.size(), -1);
    int index = 0;
    for (int i = 1; i < ranked.size(); i++) {
        if (ranked[i] == ranked[i - 1]) {
            ranked.erase(ranked.begin() + i);
        }
    }

    ranked.push_back(0);
    //binary search
    for (int i = 0; i < player.size(); i++) {
        int middle, left = 0, right = ranked.size() - 2;
        if (player[i] >= ranked[0]) {
            result[index] = 1;
            if (player[i] > ranked[0]) {
                ranked.insert(ranked.begin() + 0, player[i]);
            }
        } else {
            while (left <= right) {
                middle = (left + right) / 2;
                if (ranked[middle] == player[i]) {
                    result[index] = middle + 1;
                    break;
                }
                if (ranked[middle] > player[i] && player[i] > ranked[middle + 1]) {
                    result[index] = middle + 2;
                    //if (player[i] > ranked[middle + 1])
                        ranked.insert(ranked.begin() + result[index] - 1, player[i]);
                    break;
                }
                if (ranked[middle - 1] > player[i] && player[i] > ranked[middle]) {
                    result[index] = middle;
                    //if (ranked[middle - 1] > player[i])
                        ranked.insert(ranked.begin() + result[index], player[i]);
                    break;
                }
                if (ranked[middle] > player[i]) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
        }
        index++;
    }
    for (int i = 0; i < ranked.size(); i++) {
        cout << " " << ranked[i];
    }
    cout << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << " " << result[i];
    }
    cout << endl;
    //return result;
}
/*vector< int > climbingLeaderboard(vector< int > ranked, vector< int > player) {
    vector< int > result(player.size(), -1);
    int index = 0;
    for (int i = 1; i < ranked.size(); i++) {
        if (ranked[i] == ranked[i - 1]) {
            ranked.erase(ranked.begin() + i);
        }
    }
    
    ranked.push_back(0);
    //binary search
    for (int i = 0; i < player.size(); i++) {
        int middle, left = 0, right = ranked.size() - 2;
        if (player[i] >= ranked[0]) {
            result[index] = 1;
            if (player[i] > ranked[0]) {
                ranked.insert(ranked.begin() + 0, player[i]);
            }
        } else {
            while (left <= right) {
                middle = (left + right) / 2;
                if (ranked[middle] == player[i]) {
                    result[index] = middle + 1;
                    break;
                }
                if (ranked[middle] > player[i] && player[i] >= ranked[middle + 1]) {
                    result[index] = middle + 1 + 1;
                    if (player[i] > ranked[middle + 1])
                        ranked.insert(ranked.begin() + result[index] - 1, player[i]);
                    break;
                }
                if (ranked[middle - 1] >= player[i] && player[i] > ranked[middle]) {
                    result[index] = middle - 1 + 1;
                    if (ranked[middle - 1] > player[i])
                        ranked.insert(ranked.begin() + result[index] - 1, player[i]);
                    break;
                }
                if (ranked[middle] > player[i]) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
        }
        index++;
    }
    return result;
}*/