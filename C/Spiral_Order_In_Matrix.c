#include<stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    printf("\n");

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int start_row = 0, end_row = n-1, start_column = 0, end_column = m-1;

    while(start_row <= end_row && start_column <= end_column)
    {
        for(int col = start_column; col <= end_column; col++)
        {
            printf("%d ", a[start_row][col]);
        }
        start_row++;

        for(int row = start_row; row<=end_row; row++)
        {
            printf("%d ", a[row][end_column]);
        }
        end_column--;

        for(int col = end_column; col>=start_column; col--)
        {
            printf("%d ", a[end_row][col]);
        }
        end_row--;

        for(int row = end_row; row>=start_row; row--)
        {
            printf("%d ", a[row][start_column]);
        }
        start_column++;

    }


    return 0;
}