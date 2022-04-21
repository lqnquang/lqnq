#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

struct Date{
	int d, m, y;

	Date(int d, int m, int y){
		this->d = d;
		this->m = m;
		this->y = y;
	}
	void print();
};


#endif