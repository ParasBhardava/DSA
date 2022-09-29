#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int year, count = 0;
    scanf("%d", &year);
    
    while(count<15)
    {
        if(year%400 == 0 || (year%4 == 0 && year%100 != 0))
           {
               printf("%d " , year);
               count = count+1;
           }
           year = year+1;
    }
    
    return 0;
}
