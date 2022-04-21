#include <iostream>
//#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cout << "The length of array: ";
    cin >> n;
    int arr_a[n], arr_b[n + 1];
    for (int i = 0; i < n; i++)
        cin >> arr_a[i];
    for (int i = 0; i < n + 1; i++)
        cin >> arr_b[i];
    sort(arr_a, arr_a + n);
    sort(arr_b, arr_b + n + 1);
    int index = 0;
    while (index < n) {
        if (arr_a[index] != arr_b[index]) {
            cout << arr_b[index] << endl;
            return 0;
        }
        index++;
    }
    cout << arr_b[n] << endl;
    return 0;
}