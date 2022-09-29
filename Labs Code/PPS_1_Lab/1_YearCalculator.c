#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int num, year, month, days;
    scanf("%d", &num);
    
    year = num/360;
    month = (num - 360*year)/30;
    days = num - 360*year - 30*month;
    
    printf("%d:%d:%d", year, month, days);
    
    
    return 0;
}
