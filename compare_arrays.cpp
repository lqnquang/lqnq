#include <iostream>
using namespace std;
const int maxnum = 10000;
bool compare(int arrA[], int arrB[], int n);
int main() {
    int n;
    cin >> n;
    int arrayA[maxnum], arrayB[maxnum];
    for (int i = 0; i < n; i++)
        cin >> arrayA[i];
    for (int i = 0; i < n; i++)
        cin >> arrayB[i];
    if (compare(arrayA, arrayB, n) == true)
        cout << "YES";
    else  
        cout << "NO";
    return 0;
}
bool compare(int arrA[], int arrB[], int n) {
    for (int i = 0; i < n; i++) {
        if (arrA[i] != arrB[i]) return (false);
    }
    return (true);
}
