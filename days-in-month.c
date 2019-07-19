#include <stdio.h>
int isLeapYear(int year)
{
    int leap;
    if ((year%4==0 && year%100!=0) || year%400==0) {
        leap=1;
    }
    else{
        leap=0;
    }
    return leap;
}
void main()
{
    int inyear,inmonth,out=0,leap;
    printf("--How Many Days In a Particular Month of Year--\n\n");
    printf("Please input - year/month: ");
    scanf("%d/%d",&inyear,&inmonth);
    
    switch (isLeapYear(inyear)) {
        case 0:
            leap=0;
            break;
         case 1:
            leap=1;
            break;
    }
    switch (inmonth) {
        case 4:
        case 6:
        case 9:
        case 11: out=30; break;
        case 2:
            if(leap==1){
                out=29;
            } else {
                out=28;
            } break;
        default: out=31; break;
    }
    printf("\n\n\nThe month (of year) you entered have %d days.\n\nThank you for using this program\n\n",out);
}
