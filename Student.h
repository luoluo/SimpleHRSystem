#include "People.h"
class
Student : public People {
public:
	static int total;
	static ofstream *stuout;
	static Student **students;
	string classId;
	Student(string name="xx", string index="xx", string classId="s1", string sex="M", string id="12345", int year=1990, int month=1, int day=1)
		:People(name, index, sex, id, year, month, day) {
		this -> classId = classId;
	}
	int
	showInfo() {
		this -> People::showInfo();
		cout << this -> classId << " ";	
		cout << endl;
	}
	int
	writeStudentInfo() {
		this -> People::writePeopleInfo(stuout);
		*stuout << classId << endl;
	}
};
ofstream *Student::stuout = new ofstream("newStudentInfo.txt");
