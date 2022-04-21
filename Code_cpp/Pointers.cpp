#include <iostream>
#include <cstring>
using namespace std;

int* getPointerToTen(); //gan gia tri cho pointer
void multiphy(int *n, int k);   //nhan mot so len n lan
void swap(int *a, int *b);  //hoan doi
int* getPointerToArray(int n);  //nhap gia tri vao mang
double* getSquare(double number);   //tra ve binh phuong cua mot so
int* merge(int* firstArr, int lenArr1, int* secondArr, int lenArr2);    //ghep hai mang va sap xep
int** inputMatrix(int nRows, int nCols);    //nhap mang hai chieu
void printMatrix(int** matrix, int nRows, int nCols);   //xuat mang hai chieu
int** transpose(int** matrix, int nRows, int nCols);    //ma tran chuyen vi
void reverse(char *s);  //dao nguoc xau bang con tro
void rFilter(char *s);  //loc ky tu trong xau
int main() {
    /* //merge
    int lenArr1 = 5, lenArr2 = 5;
    int *Arr1 = getPointerToArray(lenArr1);
    int *Arr2 = getPointerToArray(lenArr2);
    int *mergeArr = merge(Arr1, lenArr1, Arr2, lenArr2);
    for (int i = 0; i < lenArr1 + lenArr2; i++) {
        cout << mergeArr[i] << " ";
    }*/

    /* //input && print matrix
    int nRows = 2, nCols = 3;
    int **matrix = inputMatrix(2, 3);
    printMatrix(matrix, nRows, nCols);*/

    /* //transpose matrix
    int nRows = 4, nCols = 3;
    int **matrix = inputMatrix(nRows, nCols);
    int **new_matrix = transpose(matrix, nRows, nCols);
    printMatrix(new_matrix, nCols, nRows);*/

    /* //reverse
    char *s;
    s = new char[10];
    cin >> s;
    reverse(s);
    cout << s;*/

    /* //rFilter
    char *s;
    s = new char[5];
    cin >> s;
    rFilter(s);
    cout << s;*/
}
int* getPointerToTen() {
    int *pInt = new int;
    *pInt = 10;
    return pInt;
}    
void multiphy(int *n, int k) {
    if (n != NULL)
        *n = (*n) * k;
}
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int* getPointerToArray(int n) {
    int *arr = new int(n);
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    return arr;
}
double* getSquare(double number) {
    double *square = &number;
    *square *= *square;
    return square;
}
int* merge(int* firstArr, int lenArr1, int* secondArr, int lenArr2) {
    int *mergeArr = new int (lenArr1 + lenArr2);
    bool key = true;
    if (firstArr[0] < firstArr[lenArr1 - 1])
        key = true;
    else    
        key = false;
    int firstIndex = 0, secondIndex = 0, mergeIndex = 0;
    if (key == true) {
        while (firstIndex < lenArr1 && secondIndex < lenArr2) {
            if (firstArr[firstIndex] <= secondArr[secondIndex]) {
                mergeArr[mergeIndex] = firstArr[firstIndex];
                firstIndex++;
            } else {
                mergeArr[mergeIndex] = secondArr[secondIndex];
                secondIndex++;
            }
            mergeIndex++;
        }
    } else {
        while (firstIndex < lenArr1 && secondIndex < lenArr2) {
            if (firstArr[firstIndex] >= secondArr[secondIndex]) {
                mergeArr[mergeIndex] = firstArr[firstIndex];
                firstIndex++;
            } else {
                mergeArr[mergeIndex] = secondArr[secondIndex];
                secondIndex++;
            }
            mergeIndex++;
        }
    }
    while (firstIndex < lenArr1) {
        mergeArr[mergeIndex] = firstArr[firstIndex];
        mergeIndex++;
        firstIndex++;
    }
    while (secondIndex < lenArr2) {
        mergeArr[mergeIndex] = secondArr[secondIndex];
        mergeIndex++;
        secondIndex++;
    }
    return mergeArr;
}
int** inputMatrix(int nRows, int nCols) {
    int** matrix = new int*[nRows];
    for (int i = 0; i < nRows; i++) {
        matrix[i] = new int[nCols];
        for (int j = 0; j < nCols; j++) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}
void printMatrix(int** matrix, int nRows, int nCols) {
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int** transpose(int** matrix, int nRows, int nCols) {
    int** transposeMatrix = new int*[nCols];
    for (int i = 0; i < nCols; i++) {
        transposeMatrix[i] = new int[nRows];
    }
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            transposeMatrix[j][i] = matrix[i][j];
        }
    }
    return transposeMatrix;
}
void reverse(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char tmp = *(s + i);
        *(s + i) = *(s + len - 1 - i);
        *(s + len - 1 - i) = tmp;
    }
}
void rFilter(char *s) {
    int len = strlen(s) - 1;
    while (len >= 0) {
        if (!isalpha(*(s + len))) {
            *(s + len) = '_';
        } else {
            break;
        }
        len--;
    }
}