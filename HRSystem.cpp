#include <stdio.h>
#include <iostream>
#include <string>
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
		cout << this -> name << "\t" << this -> index << endl;
		this -> birthday.showDate();
		return 0;
	}
};
int
init() {
	return 0;
}
int
display() {
	return 0;
}
int
sort() {
	return 0;
}
int
search() {
	return 0;
}
int
edit() {
	return 0;	
}
int
add() {
	return 0;
}
int
remove() {
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
			case 1: display(); break;
			case 2: sort(); break;
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
	People* p = new People("lili", "000", "M", "12345678", 2008, 10, 12);
	p -> showInfo();
}
int
main () {
	init();
	operation();
	return 0;
}
