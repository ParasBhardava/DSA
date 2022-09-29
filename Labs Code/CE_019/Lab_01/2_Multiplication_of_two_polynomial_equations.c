#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    int *equation1 = (int *)malloc((n+1)*sizeof(int));
    int *equation2 = (int *)malloc((n+1)*sizeof(int));
    int *answer = (int *)malloc((2*n+1)*sizeof(int));

    if(equation1)
    {
        for(int i=0; i<=n; i++)
           scanf("%d", &equation1[i]);
    
    }
    
    if(equation2)
    {
        for(int i=0; i<=n; i++)
            scanf("%d", &equation2[i]);    
    }
    
    if(answer)
    {
        for(int i=0; i<2*n+1; i++)
            answer[i] = 0;
        
        for(int i =0; i<=n; i++)
            for(int j=0; j<=n; j++)
                answer[i+j] += equation1[i] * equation2[j];
        
        for(int i=0; i<2*n+1; i++)
            printf("%d ", answer[i]);
    }
    
    free(equation1);
    free(equation2);
    free(answer);
    
    
    return 0;
}
