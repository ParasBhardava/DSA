#include <stdio.h>
#include <stdlib.h>

int is_safe(int n, int (*arr)[n], int x, int y)
{
    for (int row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
            return 0;
    }

    int row = x, column = y;
    while (row >= 0 && column >= 0)
    {
        if (arr[row][column] == 1)
            return 0;

        row--;
        column--;
    }

    row = x, column = y;
    while (row >= 0 && column < n)
    {
        if (arr[row][column] == 1)
            return 0;

        row--;
        column++;
    }

    return 1;
}

int N_Queen(int n, int (*arr)[n], int x)
{
    if (x >= n)
        return 1;

    for (int column = 0; column < n; column++)
    {
        if (is_safe(n, arr, x, column))
        {
            arr[x][column] = 1;

            if (N_Queen(n, arr, x + 1))
                return 1;

            arr[x][column] = 0; // Backtracking
        }
    }
    return 0;
}

int main()
{

    int n;
    scanf("%d", &n);

    int(*arr)[n];
    arr = (int(*)[n])malloc(n * n * sizeof(int));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = 0;

    if (N_Queen(n, arr, 0))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}