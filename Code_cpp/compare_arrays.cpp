#include <iostream>
using namespace std;
const int maxnum = 10000;
//bool compare(int arrA[], int arrB[], int n);
void readArray(int array[], int n) {
    for (int i = 0; i < n; i++) 
        cin >> array[i];
}

bool compareArray(int array1[], int array2[], int n) {
    for (int i = 0; i < n; i++) {
        if (array1[i] != array2[i]) 
            return (false);
    }
    return (true);
}

int main() {
    int n;
    cin >> n;
    int arrayA[maxnum], arrayB[maxnum];
    /*for (int i = 0; i < n; i++)
        cin >> arrayA[i];
    for (int i = 0; i < n; i++)
        cin >> arrayB[i];*/
    if (compareArray(arrayA, arrayB, n))
        cout << "YES";
    else  
        cout << "NO";
    return 0;
}
/*bool compare(int arrA[], int arrB[], int n) {
    for (int i = 0; i < n; i++) {
        if (arrA[i] != arrB[i]) return (false);
    }
    return (true);
}*/
