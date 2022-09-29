#include<stdio.h>

int main()
{
    int n, m;

    scanf("%d %d", &m, &n);
    printf("\n");
    int matrix[m][n];

    for(int i = 0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\n");

    for (int i=0; i<n; i++)
    {
        for(int j = i; j<m; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp; 
        }
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}