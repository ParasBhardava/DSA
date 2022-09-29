#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
    char *operation;
    int num1, num2;
    operation = argv[1];
    num1 = atoi(argv[2]);
    num2 = atoi(argv[3]);

    printf("Operation is: %s\n", operation);
    printf("num1 is: %d\n", num1);
    printf("num2 is: %d\n", num2);

    if( !(  strcmp(operation, "add") ) )
    {
        printf("Sum of bum1 and num2 is: %d\n", num1+num2);
    }

    if( !(  strcmp(operation, "subtract") ) )
    {
        printf("Subtraction of num1 and num2 is: %d\n", num1-num2);
    }

    if( !(  strcmp(operation, "multiply") ) )
    {
        printf("Multiplication of num1 and num2 is: %d\n", num1*num2);
    }

    if( !(  strcmp(operation, "divide") ) )
    {
        printf("Divition of num1 and num2 is: %f\n", (float)num1/num2);
    }

    return 0;
}