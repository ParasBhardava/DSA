#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int num;
    scanf("%d", &num);

    int num1 = num; 
    long long int i = 1; 
    long long int binary = 0;
    while(num1 != 0)
    {
        int remainder = num1%2;
        num1 = num1/2;
        binary = binary + (remainder*i);
        i = i*10;
    }
    
    int j = 1, num2 = num, octal = 0;
    while(num2 != 0)
    {
        int remainder = num2%8;
        num2 = num2/8;
        octal = octal + (remainder*j);
        j = j*10;
    }
    printf("%lld\n", binary);
    printf("%d\n", octal);

    int hexadecimal = 0, base = 16, num3 = num, base_power = 1;
    while(num3/base_power != 0){
    base_power*= base;
    }

    base_power /= base;
    
    if(num3 == 0)
    printf("0");
    while(base_power != 0)
    {
        hexadecimal = num3/base_power;
        num3 %= base_power;
        base_power /= base;
        if(hexadecimal>9 && hexadecimal<16)
            printf("%c", hexadecimal-10+'A');
        else
            printf("%d", hexadecimal);
    } 
    
    return 0;
}
    