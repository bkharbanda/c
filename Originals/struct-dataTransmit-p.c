#include <stdio.h>
struct data
{int a,b,c;};
void func(struct data *parm)
{
	printf("parm->a: %d	parm->b: %d	parm->c: %d\n",parm->a,parm->b,parm->c);
	printf("Change...\n");
	parm->a=2;	parm->b=3;	parm->c=parm->a*parm->b;
	printf("parm->a: %d	parm->b: %d parm->c: %d\n",parm->a,parm->b,parm->c);
	printf("Return...\n\n");
}
void main()
{
	struct data arg;
	arg.a=5;	arg.b=3;	arg.c=arg.a*
		arg.b;
	printf("arg.a: %d	arg.b: %d	arg.c: %d\n"
		,arg.a,arg.b,arg.c);
	printf("Call Func()...\n\n");
	func(&arg);
	printf("arg.a: %d	arg.b: %d	arg.c: %d\n"
		,arg.a,arg.b,arg.c);
}
