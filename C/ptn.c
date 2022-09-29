#include<stdio.h>

int main()
{
    int n; 
    scanf("%d", &n);


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        printf("%d", n-j);

        for(int j = i; j<2*n-1-i; j++)
        printf("%d", n-i);

        for(int j = 2*n-1-i; j<2*n-1; j++)
        printf("%d", 3+j-1-n);
        
        printf("\n");
    }


    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-2-i; j++)
        printf("%d", n-j);

        for(int j=n-2-i; j<n+1+i; j++)
        printf("%d", 2+i);

        for(int j=n+1+i; j<2*n-1; j++)
        printf("%d", 3+j-1-n);
     
        printf("\n");
    }
    return 0;
}