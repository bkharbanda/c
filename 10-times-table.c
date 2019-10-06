#include <stdio.h>
void main()
{
    int i,j,result; //variable declaration
    for (i=1; i<10; i++) {   
        printf("%4d",i);   //%4d allots 4 character spaces for each output 
    }
    printf("\n***************************************\n");
    for (i=1;i<10;i++){     
        for (j=1; j<10; j++) {
            result=i*j;      
            printf("%4d",result);
        }
        printf("\n");
    }
    printf("\n\n");
}

