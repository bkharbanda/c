//
//  main.c
//  firstPrj
//
//  Created by HedyLee on 04/06/2019.
//  Copyright 2019 HedyLee. All rights reserved.
//
//  Last, grand C-programming language assingment!!!
//  Date calc: days between dd/mm/yyyy and dd/mm/yyyy.
//

#include "stdio.h"
#include "time.h"
struct date
{
	int day,month,year;
};
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
void swap(struct date *p_date1,struct date *p_date2)
{
	struct date tempDate;
	tempDate.day=p_date1->day;
    tempDate.month=p_date1->month;
    tempDate.year=p_date1->year;
        
    p_date1->day=p_date2->day;
    p_date1->month=p_date2->month;
    p_date1->year=p_date2->year;
        
    p_date2->day=tempDate.day;
    p_date2->month=tempDate.month;
    p_date2->year=tempDate.year;
}

void main()
{
	//int year1,month1,day1,date2.year,date2.month,date2.day,tempDate.day,tempDate.month,tempDate.year;
    struct date date1,date2;
	int i,out,out1,out2,flag=0;
    int choice;
    int ret;
    char c;
    
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = gmtime ( &rawtime );
    out=out1=out2=0;
    
    //  input
    printf("--Date Calculator--\nThis program allows you to enter a day, month and a year, then another set of date, to calculate how many days are inbetween. Enjoy.\n\nStart by entering the first date, \nif you wan't to enter a custom date, enter '1', \nif you wan't to use today, enter '2'.\n\nEnter 1 or 2: ");
    
	// do while is for throwing away useless things and getting the useful
    do
    {
        ret=scanf("%d",&choice);
      
        while (ret!=1)
        {
            while (c=getchar()!='\n')
				;
       
            ret=scanf("%d",&choice);
        }
		// do while done


        switch (choice) {
            case 1:
                do
                {
                    printf("Please your starting custom date (dd/mm/yyyy): ");
                    ret=scanf("%d/%d/%d",&date1.day,&date1.month,&date1.year);
                    
                    while (ret!=3)
                    {
                        while (getchar()!='\n')
							;
                        
                        ret=scanf("%d/%d/%d",&date1.day,&date1.month,&date1.year);
                    }
                    
                    if (checkDateRange(date1.year, date1.month, date1.day)==0)
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
                date1.day = timeinfo->tm_mday;
                date1.month = (1+timeinfo->tm_mon);
                date1.year = 1900+timeinfo->tm_year;
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
        ret=scanf("%d",&choice);
        while (ret!=1)
        {
            while (getchar()!='\n') ;
            ret=scanf("%d",&choice);
        }
        
        switch (choice) {
            case 1:
                do {
                    printf("Now your end custom date (dd/mm/yyyy): ");
                    ret=scanf("%d/%d/%d",&date2.day,&date2.month,&date2.year);
                    
					// eat trash.
                    while (ret!=3) //not recieving 3 expected values
                    {
                        while (getchar()!='\n');
                        
                        ret=scanf("%d/%d/%d",&date2.day,&date2.month,&date2.year);
                    }
                    
                    if (checkDateRange(date2.year, date2.month, date2.day)==0) {
                        printf("The date you entered is NOT a date or was out of supporting range. So enter again\n");
                        flag=1;
                    }
                    else {
                        flag=0;
                    }
                } while (flag);
                break;
                
            case 2:
                date2.day = timeinfo->tm_mday;
                date2.month = (1+timeinfo->tm_mon);
                date2.year = 1900+timeinfo->tm_year;
                flag=0;
                break;
                
            default:
                printf("Please enter only 1 or 2, enter again here: ");
                flag=1;
        }

    }while (flag) ;
    
    
    //  Check if date1 is smaller than date2
    //  If not, swap the two dates
    if (date1.year>date2.year) {
        swap(&date1,&date2);
    }
    
    if (date1.year==date2.year && date1.month>date2.month) {
        swap(&date1,&date2);
        
    }

	if (date1.year==date2.year && date1.month==date2.month && date1.day>date2.day) {
        swap(&date1,&date2);
        
    }
    
    // input e.g. 05/07/1999 ~ 08/07/2003
    
    //  Step 1: 05/07/1999 ~ 31/12/1999
    if (date1.year != date2.year) {
        out=calcDaysInYearMonth(date1.year, date1.month)-date1.day;
        for (i=date1.month+1; i<=12; i++) {
            out+=calcDaysInYearMonth(date1.year, i);
        }
    }
    
    //  Step 2:  01/01/2000 ~ 01/01/2003 + prev result
    for (i=date1.year+1; i<date2.year; i++) {
        if (isLeapYear(i)) {
            out+=366;
        } else {
            out+=365;
        }
    }
    
    //  Step 3: 01/01/2003 ~ 01/05/2003 + prev results
    if (date1.year==date2.year) {
        for (i=1; i<date1.month; i++) {
            out1+=calcDaysInYearMonth(date1.year, i);
        }
        out1+=date1.day;
        
        for (i=1; i<date2.month; i++) {
            out2+=calcDaysInYearMonth(date2.year, i);
        }
        out2+=date2.day;
        
        out=out2-out1; // calc duration between first date and yr/jan/1st, 
					   // calc duration between second date and yr/jan/1st. And now
					   // minus the two results, we will therefore get the duration 
					   // between date1 & date2. ONLY IF the years are the same.
        
    }
    else
    {
        for (i=1; i<date2.month; i++) {
            out+=calcDaysInYearMonth(date2.year, i);
        }
    
    //  Step 4: +8 (date2.day) + prev results
        out+=date2.day;
    }
    
    //  output result (int out)
    printf("\nDays of duration between: %d/%d/%d and %d/%d/%d is... %d!\n\nThank you for using this program.\n--Date Calculator--\n\n\n",date1.day,date1.month,date1.year,date2.day,date2.month,date2.year,out);
}
// line 265 here