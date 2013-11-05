#include "People.h"
class
Tutor : public Graduate{
public:
	static ofstream *stuout;
	
	Tutor() : Graduate() {

	}
//	Tutor(string name, string index, string sex="M", string id="130301", string classId="201001", int year=1981, int month=1, int day=1)
//		:Graduate (name, index, sex, id, classId, year, month, day) {
//		this -> classId = classId;
//	}
	Tutor(string name, string index, string sex="M", string id="130301", string classId="201001", int year=1981, int month=1, int day=1, Teacher *teacher=NULL)
		:Graduate (name, index, sex, id, classId, year, month, day, teacher) {
		this -> classId = classId;
	}
	int
	showInfo() {
		this -> People::showInfo();
		cout << this -> classId << " ";	
		cout << endl;
	}
	bool
	cmp(Tutor *t2) {
		return this->Graduate::cmp(t2);
	}
	int
	writeTutorInfo() {
		this -> People::writePeopleInfo(stuout);
		*stuout << classId << endl;
	}
};
ofstream *Tutor::stuout = new ofstream("newTutorInfo.txt");

