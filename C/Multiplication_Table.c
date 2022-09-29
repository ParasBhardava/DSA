#include<stdio.h>

/*
Print a multiplication table of a number entered by the user in pretty form

Example:
Input
Enter the number you want multiplication table of:
6
output:
Table of 6:

*/

int main(){
    int i;
    int num;
   printf("Enter the number you want multiplication table of:\n");
    scanf("%d", &num);

    printf("Multiplication table of %d is as follows:\n\n", num);


    for(i=1; i<=10; i++){
        printf("%d X %d = %d\n", num,i,num*i);
    }

    return 0;
}
