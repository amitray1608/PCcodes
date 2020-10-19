#include<stdio.h>

struct date{
	int  date;
	int month;
	int year;
};

struct student{
	char name[20];
	char UID[20];
	int marks;
	struct date obj;
};
//functoion decleration
void displayName(char *);
void displayUID(char *);
void displayMarks(int);
void displayDate(int, int, int );

int main(){
		struct student s;
		gets(s.name);	
		display(&s);
}

void dispkay(struct student *s1){
	s1.name;
}
