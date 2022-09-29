#include<stdio.h>

int main()
{
    int num;
    int flag = 0;
    scanf("%d", &num);

    for(int i=2; i<num; i++)
    {
        if(num%i == 0)
        {
            flag = 1;
        }
    }

    if(flag ==  1)
    {
        printf("Given number is not a Prime number");
    }
    else
    {
        printf("Given number is a Prime number");
    }
    

    return 0;
}