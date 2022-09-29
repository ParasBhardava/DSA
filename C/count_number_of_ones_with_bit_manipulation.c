#include<stdio.h>
int count_number_of_ones(int num)
{
    int count = 0;
    while(num != 0)
    {
        num  = (num & (num-1)); 
        count++;
    }   
        return count;
}


int main()
{
    int num;
    scanf("%d", &num);
    printf("%d", count_number_of_ones(num));
    return 0;
}