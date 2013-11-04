#include "People.h"
class
Teacher : public People {
public:
	static int total;
	static ofstream *stuout;
	static Teacher **teachers;
	string classId;
	Teacher(string name="xx", string index="xx", string classId="xx", string sex="x", string id="-1", int year=-1, int month=-1, int day=-1)
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
	writeTeacherInfo() {
		this -> People::writePeopleInfo(stuout);
		*stuout << classId << endl;
	}
	static int
	sdisplay() {
		int i;
		for (i = 0; i < total; i++) {
			teachers[i] -> showInfo();
		}
		return 0;
	}

};
ofstream *Teacher::stuout = new ofstream("newTeacherInfo.txt");

