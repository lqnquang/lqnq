#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int a, int b);
int LCD(int a, int b);

int main() {
    int sizeA, sizeB;
    cin >> sizeA >> sizeB;
    //int arrA[sizeA], arrB[sizeB];
    
	vector<int>arrA;
    arrA.resize(sizeA);
    vector <int> arrB;
    arrB.resize(sizeB);

    for (int i = 0; i < sizeA; i++)
        cin >> arrA[i];
    for (int i = 0; i < sizeB; i++)
        cin >> arrB[i];
        
    sort(arrA.begin(), arrA.end());
    sort(arrB.begin(), arrB.end());
    
    if (arrA[sizeA - 1] > arrB[0]) {
    	cout << 0 << endl;
    	return 0;
	} else {
		if (arrA[sizeA - 1] == arrB[0]) {
			cout << 1 << endl;
			return 0;
		}
	}
	
    int indexA = 1, indexB = arrB[0];
    for (int i = 0; i < sizeA; i++) {
    	indexA = indexA * arrA[i] / (__gcd(indexA, arrA[i]));
	}
	for (int i = 1; i < sizeB; i++) {
		indexB = __gcd(indexB, arrB[i]); 
	}
	
	int count = 0;
	for (int i = indexA; i <= indexB; i++)
		if (indexB % i == 0 && i % indexA == 0) 
			count++;
	cout << count << endl;
	
    /*int temp = 1, indexA, indexB;
    for (int i = 0; i < sizeA; i++) {
        indexA = LCD(temp, arrA[i]);
        temp = indexA;
    }
    temp = arrB[0];
    for (int i = 0; i < sizeB; i++) {
        indexB = GCD(temp, arrB[i]);
        temp = indexB;
    }
    
    int count = 0;
    for (int i = indexA; i <= indexB; i++)
        if (indexB % i == 0)
            count++;
    cout << count << endl;*/
    return 0;
}

int GCD(int a, int b) {
    while (a != b) {
        if (a > b)
            a -= b;
        else 
            b -= a;
    }
    return a;
}

int LCD(int a, int b) {
    return (a * b / GCD(a, b));
}
