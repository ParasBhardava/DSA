#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int num, i, j;
    int a=0;
    scanf("%d", &num);
    
    for(i=0; i<num; i++)
        {
        for(j=0; j<num; j++)
            {
            if(j>=i)
                {
                printf("%d", a);
                a++;
                }
            else
                {
                printf(" ");
                }
            }
        printf("\n");
        }
    
    return 0;
}