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
	People():birthday() {
		cout << "name\tindex\tsex\tid\n";
		cin >>this-> name>>this->index>>this->sex>>this->id;
	}
	People(People *people):birthday(&people->birthday){
		this->name = people->name;
		this->index = people->index;
		this->sex = people->sex;
		this->id = people->id;
	}
	int
	showInfo() {
		//printf("%s\t%s\n", this -> name, this -> index);
		cout << this -> name << "\t" << this -> index << "\t" << this -> sex << "\t" << this -> id  << "\t";
		this -> birthday.showDate();
		return 0;
	}
	bool
	cmp(People *p2) {
		return this->index.compare(p2->index) < 0;
	}
	int
	writePeopleInfo(ofstream *peoout = NULL) {
		if (peoout) {
//			cout << "write in people\n";
			*peoout<< this->name << "\t" << this->index << "\t" << this->sex << "\t" << this->id << "\t";
			this -> birthday.writeDateInfo(peoout);
		}
		return 0;
	}
};
#endif
