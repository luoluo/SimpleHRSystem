#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;
class
Date {
public:
	int year, month, day;
	Date(int year, int month, int day) {
		this -> year = year;
		this -> month = month;
		this -> day = day;
	}
	int
	showDate() {
		cout << this -> year << "/" << this -> month << "/" << this -> day << "\t";
	}
};
#endif
