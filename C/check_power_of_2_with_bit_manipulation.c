#include<stdio.h>

// check given number is power of two or not
int check_power_of_2(int num)
{
    if(num == 0)
    return 0;
    else if((num & (num-1)) == 0)
    return 1;
    else
        return 0;
}


int main()
{
    int num;
    scanf("%d", &num);
    printf("%d", check_power_of_2(num));

    return 0;
}