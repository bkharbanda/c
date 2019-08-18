#include <stdio.h>
#include <string.h>
void main()
{
	struct person
	{
		char name[30];
		int votes;
	}leader[3]={"Hedy",0,"Jack",0,"Shirley",0};

	int i,j;
	char leader_name[30];

	for(i=1;i<=10;i++)
	{
		printf("Please enter your candidate's name: ");
		scanf("%s",leader_name);
		printf("\n");
		for(j=0;j<3;j++)
		{
			if(strcmp(leader_name,leader[j].name)==0)
			{
				leader[j].votes++;
			}
		}
	}
	for(i=0;i<3;i++)
	{
		printf("%5s: %d\n",leader[i].name,leader[i].votes);
	}
	
	printf("\n\n");
}
