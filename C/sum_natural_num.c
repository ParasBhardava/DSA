#include<stdio.h>

int main(){
    int n, sum=0;
    printf("Enter the last natural number you want to sum of\n");
    scanf("%d", &n);
    // sum =1 + 2 + 3 + 4 + 5 +.....+n


    // Runs in Linear time
    for(int i = 0; i<n; i++){
        sum +=i;
    }
    printf("Sum of first %d natural numbers is: %d\n", n, sum);


    // Runs in constant time
    sum = n*(n+1)/2;
    printf("Sum of first %d natural numbers is: %d\n", n, sum);

    return 0;
}
