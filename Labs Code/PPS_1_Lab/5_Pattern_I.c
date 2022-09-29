#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int num, i, j;
    scanf("%d", &num);
    
    for(i=0; i<num; i++)
        {
        for(j=0; j<i+1; j++)
            {
            printf("*");
            }
        printf("\n");
        }
    
    return 0;
}