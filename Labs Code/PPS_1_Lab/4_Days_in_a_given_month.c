#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int month, year;
    scanf("%d ", &month);
    scanf("%d", &year);
    
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 )
        {
        printf("31");
        }
    
    else if(month == 4 || month == 6 || month == 9 || month == 11)
        {
        printf("30");
        }
    
    else if(month == 2)
    {
    if(year%400 == 0)
        {
        printf("29");
        }
    
    else if(year%100 == 0)
        {
        printf("28");
        }
    
    else if (year%4 == 0)
        {
        printf("29");
        }
    
    else
        {
        printf("28");
        }
    }
    
    return 0;
}