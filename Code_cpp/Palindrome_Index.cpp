#include <iostream>
using namespace std;

int palindromeIndex(string s);
bool checkPalindrome(string s);

int main() {
    int num_queries;
    cin >> num_queries;
    for (int i = 0; i < num_queries; i++) {
        string s;
        cin >> s;
        cout << palindromeIndex(s) << endl;
    }
    return 0;
}

/*bool checkPalindrome(string s) {
    for (int i = 0; i <= s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) 
            return false;
    }
    return true;
}

int palindromeIndex(string s) {
    if (checkPalindrome(s)) 
        return -1;
    else {
        int index;
        for (int i = 0; i < s.size(); i++) {
            index = i;
            string copy_s = s;
            if (checkPalindrome(copy_s.erase(i, 1))) 
                return index;
        }
    }
}*/

int palindromeIndex(string s) {
	int l = s.size();
	int index = 0;
	bool key = true;
	for (int i = 0; i < l / 2; i++) {
		if (s[i] != s[l - i - 1]) {
			key = false;
			index = i;
			break;
		}
	}
	if (key == true)
		return -1;
	else {
		string copy_s = s;
		copy_s.erase(index, 1); 
		l--;
		bool superkey = true;
		for (int i = 0; i < l / 2; i++) {
			if (copy_s[i] != copy_s[l - i - 1]) {
				superkey = false;
				break;
			}
		}
		if (superkey == false)
			return l - index;
		else
			return index;		
	}
}
