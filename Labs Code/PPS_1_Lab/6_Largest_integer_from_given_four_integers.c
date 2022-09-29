#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int find_largest_number(int number_1, int number_2, int number_3, int number_4)
{
    int max1, max2;
    if(number_1 > number_2)
         max1 = number_1;
    else
        max1 = number_2;
    
    if(number_3 > number_4)
        max2 = number_3;
    else
        max2 = number_4;
    
    if(max1 > max2)
        return max1;
    else
        return max2;
}

int main()
{
    int number_1, number_2, number_3, number_4;
  	scanf("%d %d %d %d", &number_1, &number_2, &number_3, &number_4);
  	printf("%d", find_largest_number(number_1, number_2, number_3, number_4));
    
    return 0;
}