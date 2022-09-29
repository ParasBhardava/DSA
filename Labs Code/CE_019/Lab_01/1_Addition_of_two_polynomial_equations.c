#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    int *ptr1, *ptr2;
    ptr1 = malloc((n+1)*sizeof(int));
    ptr2 = malloc((n+1)*sizeof(int));
    
    if(ptr1)
    {
        for(int i=0; i<=n; i++)
            scanf("%d", &ptr1[i]);
    }
    
    if(ptr2)
    {
        for(int i=0; i<=n; i++)
            scanf("%d", &ptr2[i]);
    }
    
    for(int i=0; i<=n; i++)
        printf("%d ", ptr1[i] + ptr2[i]);
    
    free(ptr1);
    free(ptr2);

    
    return 0;
}
