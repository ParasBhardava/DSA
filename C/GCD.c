#include<stdio.h>

int find_GCD(int num1, int num2)
{
    while(num2 != 0)
    {
        int rem = num1 % num2;
        num1 = num2;
        num2 = rem;
    }
    return num1;
}

int main()
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    int gcd = find_GCD(num1, num2);
    printf("%d\n", gcd);

    return 0;
}

// NOTE :
// A*B = GCD(A, B)*LCM(A, B)