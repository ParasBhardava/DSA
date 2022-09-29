#include<stdio.h>

int reverse(int num){
    int rev = 0;
    int remainder;
    while(num != 0){
        remainder = num%10;
        rev = rev*10 + remainder;
        num = num/10;
    }
    return rev;
}

int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    printf("Your number is %d\n", num);
    int ReverseNumber = reverse(num);
    printf("The reverse of your number %d\n", ReverseNumber);
    return 0;
}
