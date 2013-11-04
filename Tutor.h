#include "People.h"
class
Tutor : public People {
public:
	static int total;
	static ofstream *stuout;
	static Tutor **students;
	string classId;
	Tutor(string name="xx", string index="xx", string classId="xx", string sex="x", string id="-1", int year=-1, int month=-1, int day=-1)
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
	writeTutorInfo() {
		this -> People::writePeopleInfo(stuout);
		*stuout << classId << endl;
	}
};
ofstream *Tutor::stuout = new ofstream("newTutorInfo.txt");

