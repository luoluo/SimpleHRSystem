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
			string name, index, sex;
			while (!stuin.eof() && 
				stuin >> name >> index >> sex ) {
				cout << "|" << name << "|" << index << "|" << sex << endl;
				graduates[totalgraduate] = new Graduate(name, index, sex);
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
		return s1->classId.compare(s2->classId) > 0;
	}
	static int
	stusort() {
		sort(graduates, graduates+totalgraduate, cmp);
		return 0;
	}
	
	static int searchByClass(string classIdx) {
		int i;
		for (i = 0; i < totalgraduate; i++) {
			if (classIdx.compare(graduates[i]->classId) == 0) {
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
			graduates[i] -> classId = newclassId;
			cout << i << endl;
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
		string classIdx;
		cin >> classIdx;
		int i = searchByClass(classIdx);
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
