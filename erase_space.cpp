#include <iostream>
using namespace std;
int main() {
    string text;
    getline(cin, text);
    int countStartSpaces = 0;
    while (text[countStartSpaces] == ' ' && countStartSpaces < text.size()-1) {
        countStartSpaces++;
    }
    for (int i = 0; i < countStartSpaces; i++)
        cout << " ";
    for (int i = countStartSpaces; i < text.size(); i++) {
        if (text[i] != ' ') cout << text[i];
        else {
            cout << " ";
            int j = i + 1;
            while (text[j] == ' ') {
                j++;
            }
            i = j - 1;
        }
    }
}