#include "Student.h"
class
Graduate : public Student {
public:
	static int total;
	static ofstream *stuout;
	Teacher adviser;	
	Graduate():Student(), adviser() {
	}
	Graduate(string name, string index, string sex = "M", string id="10086", string classId="201001", int year=1980, int month=1, int day=1)
		: Student(name, index, sex, id, classId,  year,  month,  day)
		, adviser(name, index, sex, id, classId,  year,  month,  day) {

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
	}
};
ofstream *Graduate::stuout = new ofstream("newGraduateInfo.txt");
