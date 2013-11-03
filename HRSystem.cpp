#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#define STUDENT 1000
using namespace std;
class Date {
public:
	int year, month, day;
	Date(int year, int month, int day) {
		this -> year = year;
		this -> month = month;
		this -> day = day;
	}
	int
	showDate() {
		cout << this -> year << "/" << this -> month << "/" << this -> day << endl;
	}
};
class People {
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
	int
	showInfo() {
		//printf("%s\t%s\n", this -> name, this -> index);
		cout << this -> name << "\t" << this -> index << "\t";
		//this -> birthday.showDate();
		return 0;
	}
	static ofstream *temp;
	int
	writePeopleInfo(ofstream *peoout = NULL) {
		if (peoout) {
			cout << "write in people\n";
			*peoout<< this -> name << "\t" << this -> index << "\t";
		}
		return 0;
	}
};


class Student : People {
public:
	static int total;
	static ofstream *stuout;
	static Student **students;
//	Student::stuout.open("studentInfo.txt"); 
	string classId;
	Student(string name="xx", string index="xx", string classId="xx", string sex="x", string id="-1", int year=-1, int month=-1, int day=-1)
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
		//cout << data << "\t" << name << endl;
		//*stuout << this -> name << "\t" << this -> index << endl;
		this -> People::writePeopleInfo(stuout);
		*stuout << classId << endl;
	}
	static int
	sdisplay() {
		int i;
		for (i = 0; i < total; i++) {
			students[i] -> showInfo();
		}
		return 0;
	}

};
Student ** Student::students = new Student*[STUDENT];
Student ** students = new Student*[STUDENT];
ofstream *Student::stuout = new ofstream("newstudentInfon.txt");
int Student::total = 0;
int totalstudent;
int
init() {
	ifstream stuin;
	stuin.open("studentInfo.txt"); 
//		while (!stuin.eof()) {
	if (stuin.is_open()) {
		cout << "init start\n";
		char name[100];
		char index[100];
		string classId;
		while (!stuin.eof() &&
			stuin >> name >> index >> classId) {
			cout << "|" << name << "|" << index << "|" << classId<< endl;
			students[totalstudent] = new Student(name, index, classId);
			totalstudent++;
		}
		stuin.close();
	}
	cout << "init end\n";
	return 0;
}
int
display() {
	int i;
	for (i = 0; i < totalstudent; i++) {
		students[i] -> showInfo();
	}
	return 0;
}
bool
cmp(Student * s1, Student * s2) {
//	return strcmp(s1 -> classId, s2 -> classId ) > 0;
	return s1->classId.compare(s2->classId) > 0;
}
int
stusort() {
	sort(students, students+totalstudent, cmp);
	return 0;
}

int searchByClass(string classIdx) {
	int i;
	for (i = 0; i < totalstudent; i++) {
		if (classIdx.compare(students[i]->classId) == 0) {
			return i;
		}
	}
	return -1;
}
int
search() {
	string classIdx;
	cin >> classIdx;
	int i = searchByClass(classIdx);
	if (i == -1) {
		cout << "not here\n";
	} else {
		cout << i << endl;
	}
	return 0;
}
int
edit() {
	string classIdx;
	cin >> classIdx;
	int i = searchByClass(classIdx);
	if (i == -1) {
		cout << "not here\n";
	} else {
		string newclassId;
		cin >> newclassId;
		students[i] -> classId = newclassId;
		cout << i << endl;
	}
	return 0;	
}
int
add() {
	char name[100];
	char index[100];
	string classId;
	cin >> name >> index >> classId;
	students[totalstudent] = new Student(name, index, classId);
	totalstudent++;
	return 0;
}
int
remove() {
	string classIdx;
	cin >> classIdx;
	int i = searchByClass(classIdx);
	if (i == -1) {
		cout << "not here\n";
	} else {
		int j;
		for (j = i+1; j < totalstudent; j++) {
			students[j-1] = students[j];
		}
		totalstudent--;
	}
	return 0;
}
int
goback() {
	printf("returning...\n");
	return 0;
}

int
studentManage() {
	while (1) {
		int x;
		printf("1->display\t2->sort\t3->search\t4.edit\t5.add\t6.remove\t0->back\n");
		scanf("%d", &x);
		switch(x) {
//			case 1: Student::sdisplay(); break;
			case 1: display(); break;
			case 2: stusort(); break;
			case 3: search(); break;
			case 4: edit(); break;
			case 5: add(); break;
			case 6: remove(); break;
			case 0: goback(); return 0;
			default: ;
		}
	}
	return 0;
}
int
teacherManage() {
	return 0;
}
int
graduateManage() {
	return 0;
}
int
teachAssistManage() {
	return 0;
}
int
logout() {
	//write back
	int i;
	for (i = 0; i < totalstudent; i++) {
		students[i] -> writeStudentInfo();
	}
	Student::stuout -> close();
	rename("newstudentInfon.txt", "studentInfo.txt");
	printf("lt\n");
	return 0;
}
int
operation() {
	while (1) {
		int x;
		printf("1->student\t2->teacher\t3->graduate\t4.TA\t0->lt\n");
		scanf("%d", &x);
		switch(x) {
			case 1: studentManage(); break;
			case 2: teacherManage(); break;
			case 3: graduateManage(); break;
			case 4: teachAssistManage(); break;
			case 0: logout(); return 0;
			default: ;
		}
	}

}

int
test() {
//	People* p = new People("lili", "000", "M", "12345678", 2008, 10, 12);
//	p -> showInfo();
//	Student *s = new Student("lili", "000", "M", "12345678", 2008, 10, 12, "2013");
//	s -> showInfo();
	cout << Student::total << endl;
}
int
main () {
	test();
	init();
	operation();
	return 0;
}
