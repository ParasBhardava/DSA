#include<stdio.h>

int sum(int a, int b)
{
    return a+b;
}

void greetHelloAndExicute(int (*fptr)(int, int))
{
    printf("Hello\n");
    printf("The sum of 5 and 6 is: %d\n", fptr(5, 6));
}

void greeGmAndExicute(int (*fptr)(int, int))
{
    printf("Good morning\n");
    printf("The sum of 5 and 6 is: %d\n", (*fptr)(5, 6));
}

int main()
{
    int (*ptr)(int, int);
    ptr = &sum;
    greeGmAndExicute(ptr);
    greetHelloAndExicute(ptr);
    return 0;
}