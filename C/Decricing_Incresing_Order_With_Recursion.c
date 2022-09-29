#include<stdio.h>

void dec(int n)
{
    if(n == 1)
    {
        printf("1 ");
        return;
    }
    printf("%d ", n);
    dec(n-1);
}

void inc(int n)
{
    if(n == 1)
    {
        printf("1 ");
        return;
    }

    inc(n-1);
    printf("%d ", n);
}

int main()
{
    int n;
    scanf("%d", &n);
    dec(n);
    printf("\n");
    inc(n);

   return 0; 
}