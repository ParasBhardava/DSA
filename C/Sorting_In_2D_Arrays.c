// Sorting of 2D array: First we convert 2D array into 1D array then we are sorting 1D array and then we convert
// it into 2D arrar back.  

#include <stdio.h>

int main()
{

    int n, m;
    scanf("%d %d", &n, &m);
    int arr_2D[n][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d ", &arr_2D[i][j]);

    int k = 0;
    int arr_1D[n * m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr_1D[k++] = arr_2D[i][j];

    for (int i = 0; i < (n * m) - 1; i++)
        for (int j = i + 1; j < (n * m); j++)
        {
            if (arr_1D[i] > arr_1D[j])
            {
                int temp = arr_1D[j];
                arr_1D[j] = arr_1D[i];
                arr_1D[i] = temp;
            }
        }

    k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr_2D[i][j] = arr_1D[k++];
            printf("%d ", arr_2D[i][j]);
        }
        printf("\n");
    }

    return 0;
}