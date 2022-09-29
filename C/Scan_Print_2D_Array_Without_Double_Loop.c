#include <stdio.h>

int main()
{
    int arr[3][4] = {{1, 2, 3, 4}, {5, 8, 9, 2}, {7, 0, 6, 1}};

    int i, j, a = 3, b = 4;
    for (i = 0, j = 0; j < b ? : (printf("\n"), j = 0, i++, i<a+4); j++)
    {
        printf("%d ", arr[i][j]);
    }

    return 0;
}