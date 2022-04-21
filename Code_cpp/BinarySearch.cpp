#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector< int > arr, int left, int right, int x);

int main() {
    int n, x;
    cin >> n >> x;
    vector< int > arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int result = binarySearch(arr, 0, arr.size() - 1, x);
    cout << result << endl;
    return 0;
}

int binarySearch(vector< int > arr, int left, int right, int x) {
    int middle;
    while (left <= right) {
        middle = (left + right) / 2;
        if (arr[middle] == x) {
            return middle;
        }
        if (x > arr[middle]) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return -1;
}