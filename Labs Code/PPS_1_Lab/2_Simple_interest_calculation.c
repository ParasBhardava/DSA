#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int principal_amount;
    float interest_rate_per_year, lone_tenure;
    int interest_amount;

    scanf("%d",&principal_amount);
    scanf("%f",&interest_rate_per_year);
    scanf("%f",&lone_tenure);
    interest_amount=(principal_amount*interest_rate_per_year*lone_tenure)/100;
    printf("%d", interest_amount);

    return 0;
}