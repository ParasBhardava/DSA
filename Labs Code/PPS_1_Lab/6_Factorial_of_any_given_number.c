#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long factorial(int);

int main()
{
    int n;
    long fact;
    scanf("%d", &n);
    fact = factorial(n);
    printf("%ld", fact);
  
    return 0;
}

long factorial(int num)
{
    if(num == 1 || num == 0)
        return 1;
    
    else
        return num * factorial(num-1);
}