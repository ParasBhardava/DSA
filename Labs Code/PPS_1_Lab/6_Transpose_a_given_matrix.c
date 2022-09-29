#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int row, column;
    scanf("%d %d", &row, &column);
    int matrix[row][column];
    int trans_matrix[column][row];
    
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<column; j++)
        {
            scanf("%d ", &matrix[i][j]);
        }
    }
    
    printf("%d\t%d\n", column, row);
    for(int i = 0; i<column; i++)
    {
        for(int j = 0; j<row; j++)
        {
            trans_matrix[i][j] = matrix [j][i];
            printf("%d\t", trans_matrix[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}
