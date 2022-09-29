#include<stdio.h>

int GCD(int num1, int num2)
{
    int max, min;
    if (num1 > num2)
    {
        max = num1;
        min = num2;
    }

    else
    {
        max = num2;
        min = num1;
    }

    if((max-min) == 0)
    return min;

    return GCD(min, max-min);
}

int main()
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    int gcd = GCD(num1, num2);
    printf("%d\n", gcd);

    return 0;
}