#include <stdio.h>

int main()
{ 
    int n, m;
    scanf("%d %d",&n, &m);
    int arr[n][m];

    for(int i = 0, j = 0; j < m ? : (j = 0, i++, i < n);  j++)
    {
        scanf("%d", &arr[i][j]);
    }

    printf("\n\n");
    for(int i = 0, j = 0; j < m ? : (printf("\n"), j = 0, i++, i < n);  j++)
    {
         printf("%d ", arr[i][j]);
    }
    return 0;
}