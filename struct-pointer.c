#include <stdio.h>
#include <string.h>
void main()
{
	struct student
	{
		long int num;
		char name[30];
		char sex;
		float score;
	}stu1,*p;
	p=&stu1;
	stu1.num=1;
	strcpy(stu1.name,"Hedy Li Haiyue");
	p->sex='f';
	p->score=100.99;
	printf("Student Number: %d\nName: %s\nSex: %c\nScore of recent test: %f\n\n\n"
		,stu1.num,p->name,(*p).sex,stu1.score);
}
