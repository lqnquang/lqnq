#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/*vector<int> parseInts(string str);

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    return 0;
}

vector<int> parseInts(string str) {
    vector<int> integers;
    stringstream ss(str);
    char ch;
    int tmp;
    while (ss >> tmp) {
        integers.push_back(tmp);
        ss >> ch;
    }
    return integers;
}*/

int main() {
    int n;
    cin >> n;
    string s;
    s = to_string(n) + "abc";
    cout << s;
}