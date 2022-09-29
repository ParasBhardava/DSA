#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int row_1, column_1, row_2, column_2;
    scanf("%d %d", &row_1, &column_1);
    scanf("%d %d", &row_2, &column_2);
    int matrix_1[row_1][column_1], matrix_2[row_2][column_2];

    
    for(int i = 0; i<row_1; i++)
    {
        for(int j = 0; j<column_1; j++)
        {
            scanf("%d ", &matrix_1[i][j]);
        }
    }
    
    for(int i = 0; i<row_2; i++)
    {
        for(int j = 0; j<column_2; j++)
        {
            scanf("%d ", &matrix_2[i][j]);
        }
    }
    
    
    if(row_1 == row_2 && column_1 == column_2)
    {
        printf("%d\t%d\n", row_1, column_1);
        for(int i = 0; i<row_1; i++)
        {
            for(int j = 0; j<column_1; j++)
            {
                printf("%d\t", matrix_1[i][j] + matrix_2[i][j]);
            }
            printf("\n");
        }
    }
    
    else
    {
        printf("ADDITION NOT POSSIBLE");
    }

    return 0;
}
