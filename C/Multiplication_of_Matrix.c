#include <stdio.h>

int main()
{
    int n1, n2, n3;
    printf("Enter the row of of first matrix: ");
    scanf("%d", &n1);
    printf("Enter the column of first matrix and row of first matrix: ");
    scanf("%d", &n2);
    printf("Enter the column of the second matrix: ");
    scanf("%d", &n3);

    int m1[n1][n2];
    int m2[n2][n3];

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            scanf("%d", &m1[i][j]);
        }
    }

    printf("\n");
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            scanf("%d", &m2[i][j]);
        }
    }

    int ans[n1][n3];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            ans[i][j] = 0;
        }
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            for (int k = 0; k < n2; k++)
            {
                ans[i][j] += ( m1[i][k]*m2[k][j] );
            }
        }
    }

    printf("\n");
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j<n3; j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}