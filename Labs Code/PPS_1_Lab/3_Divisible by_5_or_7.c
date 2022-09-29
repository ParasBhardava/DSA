#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{    
    int num;
    int z=0;
    scanf("%d", &num);
    num = num%7 == 0 || num%5==0 ? printf("%d", num) : printf("%d", z);
    
    return 0;
}
