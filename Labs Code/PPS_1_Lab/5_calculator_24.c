#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void addition(int num1, int num2)
    {
    int sum = num1+ num2;
    printf("%d", sum);
    }

void subtraction(int num1, int num2)
    {
    int subtract= num1-num2;
        printf("%d", subtract);
    }

int multiplication(int num1, int num2)
    {
    return num1*num2;
    }

float division(int num1, int num2)
    {
    return (float)num1/num2;
    }

int main() {
    
    int num1, num2, operation;
    scanf("%d %d %d", &num1, &num2, &operation);
     
    if(operation == 1)
        {
        addition(num1, num2);
        }
    
    else if(operation == 2)
        {
        subtraction(num1, num2);
        }
    
    else if(operation == 3)
        {
        int multiply = multiplication(num1, num2);
        printf("%d", multiply);
        }
    
    else if(operation == 4)
        {
        float divide = division(num1,num2);
        printf("%f", divide);
        }
    
    return 0;
}
