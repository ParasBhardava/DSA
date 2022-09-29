#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int num, i;
    scanf("%d", &num);
    i = printf("%d", num);
    
    if(num >= 0)
    {
        printf("%d", i);
    }
    
    if(num<0)
    {
        printf("%d", i++);
    }
    
    return 0;
}
