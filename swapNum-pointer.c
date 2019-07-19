#include <stdio.h>
void swap(int *p1, int *p2) {
    int p;
    p=*p1;
    *p1=*p2;
    *p2=p;
}
int main()
{
    int *p1, *p2,a,b;
    printf("Enter two integers seprated by a comma with no space: ");
    scanf("%d,%d",&a,&b);
    p1=&a;
    p2=&b;
    if (a<b) {
        swap(p1, p2);
    }
    printf("From biggest to smallest of your inputs: %d, %d\n\n\n",a,b);
}
