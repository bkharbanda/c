#include <stdio.h>
#include <math.h>
void main()
{
	int m,counter,logic=1,k;

	printf("Welcome, please enter a positive number and I'll tell you if it's a prime number or not!!!");
	scanf("%d",&m);
	k=(int)sqrt(m);   //to get square root
	if (m==0)
	{
		logic=2;    
	}else if (m==1)
	{
		logic=2;
	}
	else 
	{
		for (counter=2;counter<=k;counter++)
		{
			printf("counter:%d\n",counter);
			if (m%counter==0)    //checks if m is divisible by any number other than 1 and itself
			{

				logic=0;
				break;
			}
		}
	}
	if (logic==0)
	{
		printf("Your number (%d) is a composite number. \n\n",m);
	}else if (logic==1)
	{
		printf("Your number (%d) is a prime number. \n\n",m);
	}else
	{
		printf("Your number (%d) is neither a prime nor a composite number! \n\n",m);
	}
}
