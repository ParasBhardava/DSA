#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    int YY;
    int MM;
    int DD;
}date;

void next_date(date dates[], int n)
{
    for(int i=0; i<n; i++)
    {
        int is_leap_year = 0;
        if(dates[i].YY%400 == 0 || (dates[i].YY%4 == 0 && dates[i].YY%100 != 0))
            is_leap_year = 1;
        
        if(dates[i].MM == 2 && is_leap_year == 1)
        {
            if(dates[i].DD == 29)
            {
                dates[i].DD = 1;
                dates[i].MM++;
            }
            else
                dates[i].DD++;
        }
        else if(dates[i].MM == 2 && is_leap_year == 0)
        {
            if(dates[i].DD == 28)
            {
                dates[i].DD = 1;
                dates[i].MM++;
            }
            else
                dates[i].DD++;
        }
        else if(dates[i].DD == 31 && (dates[i].MM == 1 || dates[i].MM == 3 || dates[i].MM == 5 || dates[i].MM == 7 || dates[i].MM == 8 || dates[i].MM == 10) )
        {
            dates[i].DD = 1;
            dates[i].MM++;
        }
        
        else if(dates[i].DD == 30 && (dates[i].MM == 2 || dates[i].MM == 4 || dates[i].MM == 6 || dates[i].MM == 9 || dates[i].MM == 11) )
        {
            dates[i].DD = 1;
            dates[i].MM++;
        }
        else if(dates[i].DD == 31 && dates[i].MM == 12)
        {
            dates[i].DD = 1;
            dates[i].MM = 1;
            dates[i].YY++;
        }
        else
            dates[i].DD++;
        
        printf("%04d %02d %02d\n", dates[i].YY, dates[i].MM, dates[i].DD);
            
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    date dates[n];
    
    for(int i =0; i<n; i++)
        scanf("%04d %02d %02d", &dates[i].YY, &dates[i].MM, &dates[i].DD);
        
    next_date(dates, n);
    
    return 0;
}