#include<stdio.h>

int get_bit(int num, int position)
{
    if( (num & (1<<position)) != 0)
    return 1;
    else 
    return 0;
}

int set_bit(int num, int position)
{
    return (num | 1<<position);
}

int clear_bit(int num, int position)
{
    return num & (~(1<<position));
}

int update_bit(int num, int position, int i)
{
    num = ( num & (~(1<<position)) );
    return (num | (i<<position) );
} 

int main()
{
    int num, position, i;
    scanf("%d %d %d", &num, &position, &i);

    //printf("%d", get_bit(num, position));
    //printf("%d", set_bit(num, position));
    //printf("%d", clear_bit(num, position));
    printf("%d", update_bit(num, position, i));
   return 0; 
}


