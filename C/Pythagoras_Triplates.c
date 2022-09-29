#include <stdio.h>

int main()
{

int num1, num2, num3;
scanf("%d %d %d", &num1, &num2, &num3);

int max = num1 > num2 ? (num1 > num3 ? num1 : num3) : (num2 > num3 ? num2 : num3);

if (max == num1)
{
    if (num1 * num1 == num2 * num2 + num3 * num3)
    {
        printf("Paythagoras Triplate");
    }
    else
    {
        printf("Not a Paythgoras Triplate");
    }
}

else if (max == num2)
{
    if (num2 * num2 == num1 * num1 + num2 * num2)
    {
        printf("Paythagoras Triplate");
    }
    else
    {
        printf("Not a Paythgoras Triplate");
    }
}

else if (max == num3)
{
    if (num3 * num3 == num1 * num1 + num2 * num2)
    {
        printf("Paythagoras Triplate");
    }
    else
    {
        printf("Not a Paythgoras Triplate");
    }
}

return 0;
}