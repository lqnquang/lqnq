#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

int maximumSwap(int n);

int main() {
    int n;
    cin >> n;
    cout << maximumSwap(n) << endl;
    return 1;
}

int maximumSwap(int num) {
    stringstream ss;
    ss << num;
    string s = ss.str();
    int flag = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        char a = s[i];
        char swap = a;
        int index = 0;
        for (int j = i + 1; j < s.size(); j++) {
            if (s[j] > a) {
                flag = 1;
                if (s[j] > swap) {
                    swap = s[j];
                    index = j;
                }
            }
        }
        if (flag == 1) {
            char tmp = s[i];
            s[i] = s[index];
            s[index] = tmp;
            break;
        }
    }
    char str[s.size()];
    for (int i = 0; i < s.size(); i++) 
        str[i] = s[i];
    int result = atoi(str);
    return result;    
}