#include "stdio.h"
#include "time.h"
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

int checkDateRange(int year, int month, int day){
    int dayInMonth;
    
    if (year>30000 || year<1) {
        return 0;
    }
    
    if (month>12 || month<1) {
        return 0;
    }
    
    dayInMonth=calcDaysInYearMonth(year, month);
    if (day>dayInMonth || day<1) {
        return 0;
    }
    
    return 1;
}

void main()
{
    int year1,month1,day1,year2,month2,day2,tempDay,tempMonth,tempYear;
    int i,choice,out,out1,out2,flag=0;
    
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = gmtime ( &rawtime );
    out=out1=out2=0;
    
    //  input
    printf("--Date Calculator--\nThis program allows you to enter a day, month and a year, then another set of date, to calculate how many days are inbetween. Enjoy.\n\nStart by entering the first date, \nif you wan't to enter a custom date, enter '1', \nif you want to use today, enter '2'.\n\nEnter 1 or 2: ");
    
    do
    {
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                do
                {
                    printf("Please your starting custom date (dd/mm/yyyy): ");
                    scanf("%d/%d/%d",&day1,&month1,&year1);
                    if (checkDateRange(year1, month1, day1)==0)
                    {
                        printf("The date you entered is NOT a date or was out of supporting range. So enter again.\n");
                        flag=1;
                    }
                    else {
                        flag=0;
                    }
                }while (flag) ;
                break;
                
            case 2:
                day1 = timeinfo->tm_mday;
                month1 = (1+timeinfo->tm_mon);
                year1 = 1900+timeinfo->tm_year;
                flag=0;
                break;
                
            default:
                printf("Please enter only 1 or 2, enter again here: ");
                flag=1;
        }
    }while (flag) ;
    
    printf("\n\nNow, enter the end date, \nif you wan't to enter a custom date, enter '1', \nif you want to use today, enter '2'.\n\nEnter 1 or 2: ");
  
    do
    {
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                do {
                    printf("Now your end custom date (dd/mm/yyyy): ");
                    scanf("%d/%d/%d",&day2,&month2,&year2);
                    if (checkDateRange(year2, month2, day2)==0) {
                        printf("The date you entered is NOT a date or was out of supporting range. So enter again\n");
                        flag=1;
                    }
                    else {
                        flag=0;
                    }
                } while (flag);
                break;
                
            case 2:
                day2 = timeinfo->tm_mday;
                month2 = (1+timeinfo->tm_mon);
                year2 = 1900+timeinfo->tm_year;
                flag=0;
                break;
                
            default:
                printf("Please enter only 1 or 2, enter again here: ");
                flag=1;
        }
    }while (flag) ;
    
    
    //  Check if date1 is smaller than date2
    //  If not, swap the two dates
    if (year1>year2) {
        tempDay=day1;
        tempMonth=month1;
        tempYear=year1;
        
        day1=day2;
        month1=month2;
        year1=year2;
        
        day2=tempDay;
        month2=tempMonth;
        year2=tempYear;
    }
    
    if (year1==year2 && month1>month2) {
        tempDay=day1;
        tempMonth=month1;
        
        day1=day2;
        month1=month2;
        
        day2=tempDay;
        month2=tempMonth;
    }
    if (year1==year2 && month1==month2 && day1>day2) {
        tempDay=day1;
        day1=day2;
        day2=tempDay;
        
    }
    
    // input e.g. 05/07/1999 ~ 08/07/2003
    
    //  Step 1: 05/07/1999 ~ 31/12/1999
    if (year1 != year2) {
        out=calcDaysInYearMonth(year1, month1)-day1;
        for (i=month1+1; i<=12; i++) {
            out+=calcDaysInYearMonth(year1, i);
        }
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
    if (year1==year2) {
        for (i=1; i<month1; i++) {
            out1+=calcDaysInYearMonth(year1, i);
        }
        out1+=day1;
        
        for (i=1; i<month2; i++) {
            out2+=calcDaysInYearMonth(year2, i);
        }
        out2+=day2;
        
        out=out2-out1;
        
    }
    else
    {
        for (i=1; i<month2; i++) {
            out+=calcDaysInYearMonth(year2, i);
        }
    
    //  Step 4: +8 (day2) + prev results
        out+=day2;
    }
    
    //  output result(int out)
    printf("\nDays of duration between: %d/%d/%d and %d/%d/%d is... %d!\n\nThank you for using this program\n--Date Calculator--\n\n\n",day1,month1,year1,day2,month2,year2,out);
}
