#include<stdio.h>

int main()
{
    int n;
    printf("Enter the number of row or column of the matrix: ");
    scanf("%d", &n);
    printf("\n");

    int m1[n][n];
    int m2[n][n];
    int ans[n][n];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &m1[i][j]);
        }
      
    }
    printf("\n");

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &m2[i][j]);
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            ans[i][j] = m1[i][j] + m2[i][j];
        }
    }
    
    printf("\n");

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }


    return 0;
}