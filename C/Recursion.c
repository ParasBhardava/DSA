#include<stdio.h>

void func(int);

int main()
{
    int a = 28599;
    func(a);
    //getch();

    return 0;
}

void func(int a)
{
    if(a>0)
    {
        func(a/8);
        printf("%d", a%8);
    }
}