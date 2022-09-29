#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n + 1];
    arr[n] = -1;
    for (int i = 0; i < n; i++)
        scanf("%d ", &arr[i]);

    if(n==1)
    {
        printf("1");
        return 0;
    }   

    int ans = 0;
    int max = -1;
    for(int i=0; i<n; i++)
    {
        if(arr[i] > max && arr[i] > arr[i+1])
        {
        ans++;
        }
    max = max>arr[i] ? max : arr[i];
    }
    printf("%d", ans);

    return 0;
}