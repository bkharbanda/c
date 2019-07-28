#include <stdio.h>
int minOfNum(int i, int j, int k)
{
	int min;
	if(i>j)
	{
		min=j;
	}
	else
	{
		min=i;
	}
	if(min>k)
	{
		min=k;
	}
	return min;
}
void main()
{
	int i,j,k,result;
	printf("Enter 3 numbers: ");
	scanf("%d,%d,%d",&i,&j,&k);
	
	result=minOfNum(i,j,k);
	printf("min is %d\n\n\n",result);
}
