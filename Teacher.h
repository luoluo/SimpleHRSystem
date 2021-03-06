#include "People.h"
class
Teacher : public People {
public:
	static int total;
	static ofstream *stuout;
	static Teacher **teachers;
	string department;
	Teacher():People(){
		cout << "department\n";
		cin >> this -> department;
	}
	Teacher(Teacher *teacher):People(teacher) {
		this->department = teacher->department;	
	}
	Teacher(string name, string index, string sex="M", string id="23456", string department="T1", int year=1700, int month=1, int day=1)
		:People(name, index, sex, id, year, month, day) {
		this -> department = department;
	}
	int
	showInfo() {
		this -> People::showInfo();
		cout << this -> department << " ";	
		cout << endl;
	}
	bool
	cmp(Teacher *t2) {
		return this->People::cmp(t2);
	}
	int
	writeTeacherInfo() {
		this -> People::writePeopleInfo(stuout);
		*stuout << department << endl;
	}
	int
	writeTeacherInfo(ofstream *pout) {
		this -> People::writePeopleInfo(pout);
		*pout << department << endl;
	}
};
ofstream *Teacher::stuout = new ofstream("newTeacherInfo.txt");

