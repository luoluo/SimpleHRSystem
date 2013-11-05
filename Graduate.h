#include "Student.h"
class
Graduate : public Student {
public:
	static int total;
	static ofstream *stuout;
	Teacher adviser;	
	Graduate():Student(), adviser() {
	}
	Graduate(string name, string index, string sex, string id="10086", string classId="201001", int year=1980, int month=1, int day=1, Teacher *teacher=NULL)
		: Student(name, index, sex, id, classId,  year,  month,  day)
		, adviser(teacher) {

	}
//	Graduate(string name, string index, string sex = "M", string id="10086", string classId="201001", int year=1980, int month=1, int day=1)
//		: Student(name, index, sex, id, classId,  year,  month,  day)
//		, adviser(name, index, sex, id, classId,  year,  month,  day) {
//
//	}
	int
	showInfo() {
		this -> People::showInfo();
		cout << this -> classId << " ";	
		cout << endl;
	}
	bool
	cmp(Graduate *g2) {
		return this->Student::cmp(g2);
	}
	int
	writeGraduateInfo() {
		this -> Student::writeStudentInfo(stuout);
	}
};
ofstream *Graduate::stuout = new ofstream("newGraduateInfo.txt");
