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
	Date() {
		cout << "year\tmonth\tday\n";
		cin >> this->year >> this->month >> this->day;
	}
	int
	showDate() {
		cout << this -> year << "/" << this -> month << "/" << this -> day << "\t";
	}
	int
	writeDateInfo(ofstream *peoout = NULL) {
		if (peoout) {
//			cout << "write in people\n";
			*peoout << this->year << "\t" << this->month <<"\t" << this->day << "\t";
		}
		return 0;
	
	}
};
#endif
