#include <iostream>
#include <algorithm>
using namespace std;

int solve(int arr[], int size_arr);

int main() {
    int size_arr;
    cin >> size_arr;
    int arr[size_arr];
    for (int i = 0; i < size_arr; i++) 
        cin >> arr[i];
    sort(arr, arr + size_arr);
    cout << solve(arr, size_arr);
    return 0;
}

int solve(int arr[], int size_arr) {
    int count = 1, max_count = 1;
    for (int i = 1; i < size_arr; i++) {
        if (arr[i] == arr[i - 1]) count++;
        else count = 1;
        if (count > max_count) max_count = count;
    }
    return (size_arr - max_count);
}