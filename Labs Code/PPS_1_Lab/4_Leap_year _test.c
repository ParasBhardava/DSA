#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int year;
    scanf("%d", &year);
    
    if(year%400 == 0)
        {
        printf("yes");
        }
    
    else if(year%100 == 0)
        {
        printf("no");
        }
    
    else if (year%4 == 0)
        {
        printf("yes");
        }
    
    else
        {
        printf("no");
        }
    
    return 0;
}