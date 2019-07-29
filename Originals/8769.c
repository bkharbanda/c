#include <stdio.h>
void main()
{
    int count=0,a,b,c,d,num;
    printf("Here are the numbers, which units place is bigger than thousands, thousands place is bigger than hundreds and hundreds place is bigger than tens: \n");
    for (num=1000; num<=9999; num++) {
        a=num/1000;
        b=(num-(a*1000))/100;
        c=(num-(b*100)-(a*1000))/10;
        d=num-(c*10)-(b*100)-(a*1000);
        if (d<=a) {
            continue;
        }else if (a<=b) {
            continue;
        }else if (b<=c) {
            continue;
        }else {
            printf("%d\n",num);
            count++;
        }
    }
    printf("Total: %d\n\n",count);
}
