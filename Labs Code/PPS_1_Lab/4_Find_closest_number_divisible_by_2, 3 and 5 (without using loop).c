#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int num, remainder;
    scanf("%d", &num);
    remainder = num%30;
    
    if(remainder == 0)
        {
        printf("%d", num);
        }
    
    else if(remainder <= 15)
        {
        num -= remainder;
        printf("%d", num);
        }
    
    else if(remainder > 15)
        {
        num += 30-remainder;
        printf("%d", num);
        }
    
        return 0;
}