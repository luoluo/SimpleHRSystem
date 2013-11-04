#include "Teacher.h"
#define TEACHER 1000
class
TeacherManager {
private:
	static TeacherManager *_instance;
	static Teacher **teachers;
	static int totalteacher;
	TeacherManager() {
	}
public:
	static TeacherManager *
	getManager() {
		if (_instance == NULL) {
			_instance = new TeacherManager();	
			teachers = new Teacher*[TEACHER];
			init();
		}
		return _instance;
	}
	static int
	init() {
		ifstream stuin;
		stuin.open("teacherInfo.txt"); 
	//		while (!stuin.eof()) {
		if (stuin.is_open()) {
			cout << "init start\n";
			char name[100];
			char index[100];
			string classId;
			while (!stuin.eof() &&
				stuin >> name >> index >> classId) {
				cout << "|" << name << "|" << index << "|" << classId<< endl;
				teachers[totalteacher] = new Teacher(name, index, classId);
				totalteacher++;
			}
			stuin.close();
		}
		cout << "init end\n";
		return 0;
	}
	static bool
	cmp(Teacher * t1, Teacher * t2) {
	//	return strcmp(s1 -> classId, s2 -> classId ) > 0;
		return t1->People::index.compare(t2->People::index) > 0;
	}
	static int
	stusort() {
		sort(teachers, teachers+totalteacher, cmp);
		return 0;
	}
	
	static int searchByIndex(string index) {
		int i;
		for (i = 0; i < totalteacher; i++) {
			if (index.compare(teachers[i]->People::index) == 0) {
				return i;
			}
		}
		return -1;
	}
	static int
	search() {
		string index;
		cin >> index;
		int i = searchByIndex(index);
		if (i == -1) {
			cout << "not here\n";
		} else {
			cout << i << endl;
		}
		return 0;
	}
	static int
	edit() {
		string index;
		cin >> index;
		int i = searchByIndex(index);
		if (i == -1) {
			cout << "not here\n";
		} else {
			string newIndex;
			cin >> newIndex;
			teachers[i] -> People::index = newIndex;
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
		teachers[totalteacher] = new Teacher(name, index, classId);
		totalteacher++;
		return 0;
	}
	static int
	remove() {
		string index;
		cin >> index;
		int i = searchByIndex(index);
		if (i == -1) {
			cout << "not here\n";
		} else {
			int j;
			for (j = i+1; j < totalteacher; j++) {
				teachers[j-1] = teachers[j];
			}
			totalteacher--;
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
		for (i = 0; i < totalteacher; i++) {
			teachers[i] -> showInfo();
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
		for (i = 0; i < totalteacher; i++) {
			teachers[i] -> writeTeacherInfo();
		}
		Teacher::stuout -> close();
		rename("newTeacherInfo.txt", "teacherInfo.txt");
	}
};
TeacherManager * TeacherManager::_instance = NULL;
Teacher ** TeacherManager::teachers = NULL;
int TeacherManager::totalteacher = 0;
