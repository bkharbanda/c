// game explanation (Work in progress): So there are n monkeys, 
// and they are tryin to figure out who is the king. They start by sitting in
// a circle and

#include <stdio.h>
void main()
{
	int k=1,i,counter,m,n;//10 monkeys,counting to 3
	printf("explanation comming soon");
	
	do//to prevent inputting a 0 or 100+
	{
		printf("\nn:");//input the n
		scanf("%d",&n);
		if(n<0 || n>100)
		{
			printf("ERROR!!! DIDN'T YOU READ THE EXPLANATION???");
			printf("\nPLEASE INPUT AGAIN!!!");
		}
	}while(n<0 || n>100);


	printf("\nm:");//input the m
	scanf("%d",&m);
	int monks[100];//max=100

	printf("\n\n");

	for(i=0;i<n;i++)//put everything to 1
	{
		monks[i]=1;
	}
	
	counter=0;
	while(counter<n)
	{
		for(i=0;i<n;i++)
		{
			if(monks[i]!=0)//if you're already out, skip
			{
				if(k==m)//if we counted to m, ��� 1
				{
					monks[i]=0;//YOU'ER OUT
					printf("%4d",i+1);//print out the 'out monkeys'
					counter++;
					k=1;//yes we ve counted to m, now 1
				}
				else
				{
					k++; //skip
				}
			}
		}
	}
	
	printf(" <-- THIS IS THE KING!!!\n\n\n"); //last one out
}
