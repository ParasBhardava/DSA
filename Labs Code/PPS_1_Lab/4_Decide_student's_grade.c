#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    
    int marks;
    scanf("%d", &marks);
    
    if(marks >= 90)
        {
        printf("AA");
        }

    else if(marks >= 80  && marks <90)
        {
        printf("AB");
        }

    else if(marks >= 70  && marks <80)
        {
        printf("BB");
        }

    else if(marks >= 60 && marks <70)
        {
        printf("BC");
        }

    else if(marks >= 50  && marks <60)
        {
        printf("CC");
        }

     else if(marks >= 40  && marks <50)
        {
        printf("CD");
        }

     else if(marks < 40)
        {
        printf("DD");
        }

    return 0;
}