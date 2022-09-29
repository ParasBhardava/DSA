/* Backtracking is an algorithem-technique for solving recursively problems by trying to build every possible        
   solution incrementally and removing those solutions that fail to satisfy the contraints of the problem at any 
   point of time.
*/

// Rate in Maze

/* Input                                           Output
{1,0,1,0,1}                                        {1,0,0,0,0}
{1,1,1,1,1}                                        {1,1,1,1,0}
{0,1,0,1,0}                                        {0,0,0,1,0}
{1,0,0,1,1}                                        {0,0,0,1,1}
{1,1,1,0,1}                                        {0,0,0,0,1}
*/

#include <stdio.h>
#include <stdlib.h>

int is_safe(int n, int (*arr)[n], int x, int y)
{
    if (x < n && y < n && arr[x][y] == 1)
    {
        return 1;
    }
    return 0;
}

int rate_in_maze(int n, int (*arr)[n], int x, int y, int (*solution_arr)[n])
{
    if (x == n - 1 && y == n - 1)
    {
        solution_arr[x][y] = 1;
        return 1;
    }

    if (is_safe(n, arr, x, y))
    {
        solution_arr[x][y] = 1;
        if (rate_in_maze(n, arr, x + 1, y, solution_arr))
        {
            return 1;
        }
        if (rate_in_maze(n, arr, x, y + 1, solution_arr))
        {
            return 1;
        }
        solution_arr[x][y] = 0; // backtracking
        return 0;
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);

    int(*arr)[n];
    arr = (int(*)[n])malloc(n * n * sizeof(int));

    printf("\nInput\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d ", &arr[i][j]);

    int(*solution_arr)[n];
    solution_arr = (int(*)[n])malloc(n * n * sizeof(int));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            solution_arr[i][j] = 0;

    printf("\nOutput\n");
    if (rate_in_maze(n, arr, 0, 0, solution_arr))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", solution_arr[i][j]);
            }
            printf("\n");
        }
    }

    for (int i = 0; i < n; i++)
        free(arr[i]);

    for (int i = 0; i < n; i++)
        free(solution_arr[i]);

    return 0;
}
