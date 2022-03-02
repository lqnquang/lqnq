#include <iostream>
using namespace std;
bool check_char(string s);
//kiem tra ky tu dac biet hop le
bool check_size(string s);
//kiem tra do dai hop le
bool check_firstChar(char c);
//kiem tra ky tu dau hop le

int main() {
    string text;
    getline(cin, text);
    if (check_size(text) == true && check_firstChar(text[0]) == true && check_char(text) == true)
        cout << "Valid username.";
    else cout << "Invalid username.";
    return 0;
}

bool check_char(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (isalnum(s[i]) == false) return (false);
    }
    return (true);
}
bool check_size(string s) {
    if (6 <= s.size() && s.size() <= 15) return (true);
    else return (false);
}
bool check_firstChar(char c) {
    if (isdigit(c)) return (false);
    else return (true);
}