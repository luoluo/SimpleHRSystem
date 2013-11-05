#include "Tutor.h"
#define TUTOR 1000
class
TutorManager {
private:
	static TutorManager *_instance;
	static Tutor **tutors;
	static int totaltutor;
	TutorManager() {
	}
public:
	static TutorManager *
	getManager() {
		if (_instance == NULL) {
			_instance = new TutorManager();	
			tutors = new Tutor*[TUTOR];
			init();
		}
		return _instance;
	}
	static int
	init() {
		ifstream stuin;
		stuin.open("tutorInfo.txt"); 
		if (stuin.is_open()) {
			cout << "init start\n";
			string name, index, sex;
			while (!stuin.eof() &&
				stuin >> name >> index >> sex) {
				cout << "|" << name << "|" << index << "|" << sex<< endl;
				tutors[totaltutor] = new Tutor(name, index, sex);
				totaltutor++;
			}
			stuin.close();
		}
		cout << "init end\n";
		return 0;
	}
	static bool
	cmp(Tutor * s1, Tutor * s2) {
	//	return strcmp(s1 -> classId, s2 -> classId ) > 0;
		return s1->classId.compare(s2->classId) > 0;
	}
	static int
	stusort() {
		sort(tutors, tutors+totaltutor, cmp);
		return 0;
	}
	
	static int searchByClass(string classIdx) {
		int i;
		for (i = 0; i < totaltutor; i++) {
			if (classIdx.compare(tutors[i]->classId) == 0) {
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
			tutors[i] -> classId = newclassId;
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
		tutors[totaltutor] = new Tutor(name, index, classId);
		totaltutor++;
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
			for (j = i+1; j < totaltutor; j++) {
				tutors[j-1] = tutors[j];
			}
			totaltutor--;
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
		for (i = 0; i < totaltutor; i++) {
			tutors[i] -> showInfo();
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
		for (i = 0; i < totaltutor; i++) {
			tutors[i] -> writeTutorInfo();
		}
		Tutor::stuout -> close();
		rename("newTutorInfo.txt", "tutorInfo.txt");
	}
};
TutorManager * TutorManager::_instance = NULL;
Tutor ** TutorManager::tutors = NULL;
int TutorManager::totaltutor = 0;
