#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;
string numToStri(int n) {
	stringstream ss;
	ss << n;
	return ss.str();
}
string timeConversion(string s) {
	string new_time;
	string key = s.substr(s.size() - 2, 2);
	s.erase(s.size() - 2, 2);
	string hour = s.substr(0, 2);
	if (key == "AM") {
		if (hour == "12") {
			s.erase(0, 2);
			new_time = "00" + s;
		} else {
			new_time = s;
		}
	} else {
		if (hour == "12") {
			new_time = s;
		} else {
			s.erase(0, 2);
			new_time = numToStri(atoi(hour.c_str()) + 12) + s;
		}
	}
	return new_time;
}
int main() {
	string s;
	getline(cin, s);
	cout << timeConversion(s) << endl;
}