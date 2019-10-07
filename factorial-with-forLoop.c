#include <stdio.h>
void main()
{
    int n,i,result=1;
    printf("Please input a number: ");
    scanf("%d",&n);// takes the input and stores it in the variable n.
    for (i=n; i>0; i--)//just a loop which will run n times
    {
        result=i*result; //this will multiply all the number till n.
    
        
    }
    printf("The factorial of your input %d is %d\n\n",n,result);
}
