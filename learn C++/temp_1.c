#include<stdio.h>

# define f(x) x+x

int main()
{
    int a = 2;
    printf("%d", f(++a));
    return 0;
}
