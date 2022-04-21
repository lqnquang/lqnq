#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int k, n;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i <= n - k; i++) {
        int maxNum = -1;
        for (int j = i; j < i + k; j++) {
            maxNum = max(maxNum, arr[j]);
        }
        cout << maxNum << " ";
    }
}