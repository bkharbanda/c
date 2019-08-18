//
//  main.c
//  firstPrj
//
//  Created by HedyLee on 04/06/2019.
//  Copyright © 2019 HedyLee. All rights reserved.
//
//  Last, grand C-programming language assingment!!!
//  Date calc: days between dd/mm/yyyy and dd/mm/yyyy.
//

#include <stdio.h>
int isLeapYear(int year) {
    int leap;
    if ((year%4==0 && year%100!=0) || year%400==0) {
        leap=1;
    }
    else{
        leap=0;
    }
    return leap;
} //hi

int calcDaysInYearMonth(int year, int month) {
    int out;
    switch (month) {
        case 4:
        case 6:
        case 9:
        case 11: out=30; break;
        case 2:
            if (isLeapYear(year)) {
                out=29;
            }
            else {
                out=28;
            }
            break;
        default: out=31; break;
    }
    return out;
}

void main()
{
    int year1,month1,day1,year2,month2,day2,temp,out=0,i;
    
    //input
    printf("--Date Calculator--\nThis program allows you to enter a day, month and a year, then another set of date, to calculate how many days are inbetween. Enjoy.\n\nStart by entering the first date in this format, dd/mm/yyyy: ");
    scanf("%d/%d/%d",&day1,&month1,&year1);
    printf("Now, with the same format (dd/mm/yyyy), enter the date of the other date which will be subtracted by: ");
    scanf("%d/%d/%d",&day2,&month2,&year2);
    
    // input e.g. 05/07/1999 ~ 08/07/2003
    
    //  Step 1: 05/07/1999 ~ 31/12/1999
    out=calcDaysInYearMonth(year1, month1)-day1;
    for (i=month1+1; i<=12; i++) {
        out+=calcDaysInYearMonth(year1, i);
    }
    
    //  Step 2:  01/01/2000 ~ 01/01/2003 + prev result
    for (i=year1+1; i<year2; i++) {
        if (isLeapYear(i)) {
            out+=366;
        } else {
            out+=365;
        }
    }
    
    //  Step 3: 01/01/2003 ~ 01/05/2003 + prev results
    for (i=1; i<month2; i++) {
        out+=calcDaysInYearMonth(year2, i);
    }
    
    //  Step 4: +8 (day2) + prev results
    out+=day2;
    
    //  output result(int out)
    printf("\nDays of duration between: %d/%d/%d and %d/%d/%d is... %d!\n\nThank you for using this program\n--Date Calculator--\n\n\n",day1,month1,year1,day2,month2,year2,out);
}
