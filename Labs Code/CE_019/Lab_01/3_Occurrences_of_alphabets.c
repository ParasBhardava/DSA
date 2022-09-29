#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d", &n);
    
    char *arr = (char*)malloc((n+1)*sizeof(char));
    int *ans = (int*)calloc(26, sizeof(int));
    
    for(int i=0; i<n+1; i++)
    {
        arr[i] = getchar();
    }
    
    for(int i=0; i<=n; i++)
    {
        if(arr[i] >= 'A' && arr[i] <= 'Z')
            ans[arr[i]-'A']++;
        
        else if(arr[i] >= 'a' && arr[i] <= 'z')
            ans[arr[i]-'a']++;
    }
    
    for(int i=0; i<26; i++)
        printf("%d ", ans[i]);
    return 0;
}
