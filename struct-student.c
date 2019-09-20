#include <stdio.h>
#include <string.h>
void main()
{
	struct student
	{
		int num;
		char name[30];
		char sex;
		int age;
		struct bDate
		{
			int y;
			int m;
			int d;
		}birthday;
		char addr[100];
	};
	//struct student stu1={1,"Hedy Li Haiyue",'f',11,2007,10,4,"B-23-11 Amerin Residence, Selangor, Kuala Lumpur, Malaysia"};
	struct student stu1;
	stu1.num=1;
	strcpy(stu1.name,"John Smith");
	stu1.sex='m';
	stu1.age=0;
	stu1.birthday.y=2019;
	stu1.birthday.m=8;
	stu1.birthday.d=4;
	strcpy(stu1.addr,"BLah BLAh BLAH");

	printf("--Student 1--\nName: %s\nNo.: %d\nSexuality: %c\nAge: %d\nBirthday: %d/%d/%d\nAddress: %s\n\n\n"
		,stu1.name,stu1.num,stu1.sex,stu1.age,stu1.birthday.d,stu1.birthday.m,stu1.birthday.y,stu1.addr);
}
