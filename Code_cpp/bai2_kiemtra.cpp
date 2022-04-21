#include <iostream>
#include <vector>
using namespace std;
int main() {
    string s;
    cin >> s;
    vector<int> arr;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'C') {
            int count = 1, j = i + 1;
            while (s[j] == s[i]) {
                count++;
                j++;
            }
            arr.push_back(count);
        }
    }
    arr.push_back(0);
    int first = 0, second = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] >= first) {
            second = first;
            first = arr[i];
        }
    }
    cout << first + second << endl;
}