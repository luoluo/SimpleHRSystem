#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "StudentManager.h"
#include "TeacherManager.h"
#include "GraduateManager.h"
#include "TutorManager.h"
using namespace std;
class
Manager {
private:
	static Manager *_instance;
	static StudentManager * studentManager;
	static TeacherManager * teacherManager;
	static GraduateManager * graduateManager;
	static TutorManager * tutorManager;
	Manager() {
	}
public:
	static Manager *
	getManager() {
		if (_instance == NULL) {
			_instance = new Manager();	
			studentManager = StudentManager::getManager();
			teacherManager = TeacherManager::getManager();
			graduateManager = GraduateManager::getManager();
			tutorManager = TutorManager::getManager();
		}
		return _instance;
	}
	static int
	operation() {
		while (1) {
			int x;
			printf("1->student\t2->teacher\t3->graduate\t4.TA\t0->lt\n");
			scanf("%d", &x);
			switch(x) {
				case 1:	studentManager->manage(); break;
				case 2: teacherManager->manage(); break;
				case 3:	graduateManager->manage(); break;
				case 4: tutorManager->manage(); break;
				case 0: logout(); return 0;
				default: ;
			}
		}
	}
	static int
	logout() {
		//write back
		studentManager->writeback();
		teacherManager->writeback();
		graduateManager->writeback();
		tutorManager->writeback();
		printf("lt\n");
		return 0;
	}
};
Manager * Manager::_instance = NULL;
StudentManager * Manager::studentManager = NULL;
TeacherManager * Manager::teacherManager = NULL;
GraduateManager * Manager::graduateManager = NULL;
TutorManager * Manager::tutorManager= NULL;

int
test() {
//	People* p = new People("lili", "000", "M", "12345678", 2008, 10, 12);
//	p -> showInfo();
//	Student *s = new Student("lili", "000", "M", "12345678", 2008, 10, 12, "2013");
//	s -> showInfo();
//	cout << Student::total << endl;
	Manager *manager = Manager::getManager();
	manager -> operation();
}
int
main () {
	test();
//	init();
//	operation();
	return 0;
}
