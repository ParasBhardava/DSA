#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long long find_gcd(unsigned long long int,unsigned long long int);

int main()
{
    long long int num1, num2;
    scanf("%llu %llu", &num1, &num2);
    printf("%llu", find_gcd(num1, num2));
    
    return 0;
}

long long find_gcd(unsigned long long int num1, unsigned long long int num2)
{
    unsigned long long int max, min;
    if(num1 > num2)
        {
        max = num1;
        min = num2;
        }
    else
        {
        max = num2;
        min = num1;
        }
    
    if(max%min == 0)
        {
        return min;
        }
    else
        {
        return find_gcd(min, max%min);
        }
}
