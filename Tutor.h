#include "People.h"
class
Tutor : public Graduate{
public:
	static ofstream *stuout;
	
	Tutor() : Graduate() {

	}
	Tutor(string name="xx", string index="xx",  string sex="M", string id="130301", string classId="201001", int year=1981, int month=1, int day=1)
		:Graduate (name, index, sex, id, classId, year, month, day) {
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

