/*#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;*/

//chuyen so sang xau
/*int main() {
    int n;
    char s[20];
    cin >> n;
    itoa(n, s, 10);
    //cout <<  << endl;
    cout << s[6] << endl;
}*/
/*void reverseArray(float array[], int size) {
    for (int i = 0; i < size / 2; i++) {
        float tmp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = tmp;
    }
}
void sort(float array[], int size, bool isAscending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                float tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
    if (isAscending == false) 
        reverseArray(array, size);
}
/*string pigLatin(string word) {
    string new_word;
    if (word[0] == 'e' || word[0] == 'u' || word[0] == 'o' || word[0] == 'a' || word[0] == 'i') {
        new_word = word + "way";
    } else {
        char firstChar = word[0];
        new_word = word.erase(0, 1) + firstChar + "ay";
    }
    return new_word;
}
int main() {
    string s;
    cin >> s;
    cout << pigLatin(s);
}*/
#include <bits/stdc++.h>
using namespace std;

void findZigZagSequence(vector < int > a, int n){
    sort(a.begin(), a.end());
    int mid = (n + 1)/2;
    swap(a[mid], a[n-1]);

    int st = mid + 1;
    int ed = n - 1;
    while(st <= ed){
        swap(a[st], a[ed]);
        st = st + 1;
        ed = ed + 1;
    }
    for(int i = 0; i < n; i++){
        if(i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
}

int main() {
    int n, x;
    int test_cases;
    cin >> test_cases;

    for(int cs = 1; cs <= test_cases; cs++){
        cin >> n;
        vector < int > a;
        for(int i = 0; i < n; i++){
            cin >> x;
            a.push_back(x);
        }
        findZigZagSequence(a, n);
    }
}