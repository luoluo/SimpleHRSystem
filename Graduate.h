#include "People.h"
class
Graduate : public People {
public:
	static int total;
	static ofstream *stuout;
	static Graduate **graduates;
	string classId;
	Graduate(string name="xx", string index="xx", string classId="xx", string sex="x", string id="-1", int year=-1, int month=-1, int day=-1)
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
	writeGraduateInfo() {
		this -> People::writePeopleInfo(stuout);
		*stuout << classId << endl;
	}
};
ofstream *Graduate::stuout = new ofstream("newGraduateInfo.txt");
