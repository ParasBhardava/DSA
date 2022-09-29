#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int num, i, remainder;
    scanf("%d", &num);
    i = printf("%d", num);
    remainder = i%2;

    if(num>=0)
    {
        remainder == 0 ? 0 : printf("%d", i);
    }
    
    if(num<0)
    {
        remainder == 0 ? 0 : printf("%d", i);
    }

    return 0;
}
