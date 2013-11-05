#include "Graduate.h"
#define GRADUATE 1000
class
GraduateManager {
private:
	static GraduateManager *_instance;
	static Graduate **graduates;
	static int totalgraduate;
	GraduateManager() {
	}
public:
	static GraduateManager *
	getManager() {
		if (_instance == NULL) {
			_instance = new GraduateManager();	
			graduates = new Graduate*[GRADUATE];
			init();
		}
		return _instance;
	}
	static int
	init() {
		ifstream stuin;
		stuin.open("graduateInfo.txt"); 
//		while (!stuin.eof()) {
		if (stuin.is_open()) {
			cout << "init start\n";
			string name, index, sex, id, classId;
			string name1, index1, sex1, id1, department;
			int year, month, day; 
			int year1, month1, day1; 
			while (!stuin.eof() &&
				stuin >>name>> index>> sex>> id>> year>> month >> day >> classId >>
					name1 >> index1 >> sex1 >> id1 >> year1 >> month1>> day1 >> department) {
				Teacher* teacher = new Teacher(name1, index1, sex1, id1, department, year1, month1, day1);
				graduates[totalgraduate] = new Graduate(name, index, sex, id, classId, year, month, day, teacher);
				totalgraduate++;
			}
			stuin.close();
		}
		cout << "init end\n";
		return 0;
	}
	static bool
	cmp(Graduate * s1, Graduate * s2) {
//	return strcmp(s1 -> classId, s2 -> classId ) > 0;
		return s1->cmp(s2);
	}
	static int
	stusort() {
		sort(graduates, graduates+totalgraduate, cmp);
		return 0;
	}
	
	static int searchByIndex(string index) {
		int i;
		for (i = 0; i < totalgraduate; i++) {
			if (index.compare(graduates[i]->index) == 0) {
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
			graduates[i] = new Graduate();
		}
		return 0;	
	}
	static int
	add() {
		graduates[totalgraduate] = new Graduate();
		totalgraduate++;
		return 0;
	}
	static int
	remove() {
		string indexx;
		cin >> indexx;
		int i = searchByIndex(indexx);
		if (i == -1) {
			cout << "not here\n";
		} else {
			int j;
			for (j = i+1; j < totalgraduate; j++) {
				graduates[j-1] = graduates[j];
			}
			totalgraduate--;
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
		for (i = 0; i < totalgraduate; i++) {
			graduates[i] -> showInfo();
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
		for (i = 0; i < totalgraduate; i++) {
			graduates[i] -> writeGraduateInfo();
		}
		Graduate::stuout -> close();
		rename("newGraduateInfo.txt", "graduateInfo.txt");
	}
};
GraduateManager * GraduateManager::_instance = NULL;
Graduate ** GraduateManager::graduates = NULL;
int GraduateManager::totalgraduate = 0;
