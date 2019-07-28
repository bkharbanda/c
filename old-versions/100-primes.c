#include <stdio.h> //printf and stuff
#include <math.h> //sqrt stuff
void main()
{
	int i,m,x,count=1,flag;
	printf("Welcome, here are the first 100 prime numbers:\n\n");
	
	//x is for testing,count is for counting if there are 100
	for (x=2;count<101;x++)
	{
		flag=1;  //let's say it's a prime...
		m=(int)sqrt(x);
		//this square root it to determine if x is prime or com
		for (i=2;i<=m;i++)//i is normally for the counting in for(s)
		{
			if (x%i==0)
			{
				flag=0; //now it's not a prime, let's break.
				break;
			}

		}
		
		//if flag hasn't changed, then out guess is right,
		//it IS a prime number
		if (flag==1)
		{
			printf("%4d",x); //now let's output this result
			count++; //yay we found one (more), let's move on!	
		}
	}
}
