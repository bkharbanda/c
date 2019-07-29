#include <stdio.h>
void main()
{
    int n,i,result=1;
    printf("Please input a number: ");
    scanf("%d",&n);
    for (i=n; i>0; i--) {
        result=i*result;
    
        
    }
    printf("The factorial of your input %d is %d\n\n",n,result);
}
