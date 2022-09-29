#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int row1,column1,row2,column2;
    scanf("%d %d",&row1,&column1);
    scanf("%d %d",&row2,&column2);
    
    if(column1 ==row2)
    {
        int** matrix1 = (int **) malloc(sizeof(int *) * row1);
        for(int i=0;i<row1;i++)
        {
            matrix1[i] = (int *) malloc(sizeof(int)*column1);
        }
        
        int** matrix2=(int **) malloc(sizeof(int *) * row2);
        for(int i=0;i<row2;i++)
        {
            matrix2[i] = (int *) malloc(sizeof(int)*column2);
        }
        
        int** result = (int**) malloc(sizeof(int *) * row1);
        for(int i=0;i<row1;i++)
        {
            result[i]=(int*) calloc(sizeof(int),column2);
        }
        
        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<column1;j++)
            {
                scanf("%d",&matrix1[i][j]);
            }
        }
        
        for(int i=0;i<row2;i++)
        {
            for(int j=0; j<column2; j++)
            {
                scanf("%d",&matrix2[i][j]);
            }
        }
        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<column2;j++)
            {
                for(int k=0;k<column1; k++)
                {
                    result[i][j]+= (matrix1[i][k]) * (matrix2[k][j]);
                }
            }
        }
        printf("%d\t%d\n",row1,column2);
        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<column2;j++)
            {
                printf("%d\t",result[i][j]);
            }
            printf("\n");
        }
        
    }
    else
        printf("-1\n");
    
    return 0;
}