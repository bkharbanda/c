#include <stdio.h>
int fac(int n)
{   int f;  
    if(n<0)  printf("n<0,data error!");
    else if(n==0||n==1)  f=1;
    else f=n*fac(n-1);   //recursive function that generates factorial 
    return f;
}
void main()
{   int n, y;
    printf("Input a integer number:");
    scanf("%d",&n);
    y=fac(n);   //function call 
    printf("%d! =%10d\n",n,y);
}
