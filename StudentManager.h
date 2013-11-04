#include "Student.h"
#define STUDENT 1000
class
StudentManager {
private:
	static StudentManager *_instance;
	static Student **students;
	static int totalstudent;
	StudentManager() {
	}
public:
	static StudentManager *
	getManager() {
		if (_instance == NULL) {
			_instance = new StudentManager();	
			students = new Student*[STUDENT];
			init();
		}
		return _instance;
	}
	static int
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
	static bool
	cmp(Student * s1, Student * s2) {
	//	return strcmp(s1 -> classId, s2 -> classId ) > 0;
		return s1->classId.compare(s2->classId) > 0;
	}
	static int
	stusort() {
		sort(students, students+totalstudent, cmp);
		return 0;
	}
	
	static int searchByClass(string classIdx) {
		int i;
		for (i = 0; i < totalstudent; i++) {
			if (classIdx.compare(students[i]->classId) == 0) {
				return i;
			}
		}
		return -1;
	}
	static int
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
	static int
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
	static int
	add() {
		char name[100];
		char index[100];
		string classId;
		cin >> name >> index >> classId;
		students[totalstudent] = new Student(name, index, classId);
		totalstudent++;
		return 0;
	}
	static int
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
	static int
	goback() {
		printf("returning...\n");
		return 0;
	}
	static int
	display() {
		int i;
		for (i = 0; i < totalstudent; i++) {
			students[i] -> showInfo();
		}
		return 0;
	}
	static int
	manage() {
		while (1) {
			int x;
			printf("1->display\t2->sort\t3->search\t4.edit\t5.add\t6.remove\t0->back\n");
			scanf("%d", &x);
			switch(x) {
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
	static int 
	writeback() {
		int i;
		for (i = 0; i < totalstudent; i++) {
			students[i] -> writeStudentInfo();
		}
		Student::stuout -> close();
		rename("newstudentInfo.txt", "studentInfo.txt");
	}
};
StudentManager * StudentManager::_instance = NULL;
Student ** StudentManager::students = NULL;
int StudentManager::totalstudent = 0;
