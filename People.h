#ifndef PEOPLE_H
#define PEOPLE_H
#include "Date.h"
class
People {
public:
	string name, index, sex, id;
	Date birthday;
	People(string name, string index, string sex, string id, int year, int month, int day):birthday(year, month, day) {
//		birthday = new Date(year, month, day);
		this -> name = name;
		this -> index = index;
		this -> sex = sex;
		this -> id = id;
	}
	int
	showInfo() {
		//printf("%s\t%s\n", this -> name, this -> index);
		cout << this -> name << "\t" << this -> index << "\t" << this -> sex << "\t" << this -> id  << "\t";
		this -> birthday.showDate();
		return 0;
	}
	static ofstream *temp;
	int
	writePeopleInfo(ofstream *peoout = NULL) {
		if (peoout) {
//			cout << "write in people\n";
			*peoout<< this -> name << "\t" << this -> index << "\t";
		}
		return 0;
	}
};
#endif
