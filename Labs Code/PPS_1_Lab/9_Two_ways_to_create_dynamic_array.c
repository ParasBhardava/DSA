#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int i, j, m, n;
    
    scanf("%d %d", &m, &n);

//	one method
//	int **ip2;
//	ip2 = (int **) malloc(sizeof(int *) * m);
//	for(i = 0; i < m; i++)
//	{
//		ip2[i] = (int *) malloc(sizeof(int) * n);
//	}
    
//	another method
    int (*ip2)[n];
    ip2 = (int (*)[n]) malloc(sizeof(int) * m * n);
    
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", *(ip2 + i) + j);
        }
    }
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d\t", *(*(ip2 + i) + j));
        }
        printf("\n");
    }
    return 0;
}