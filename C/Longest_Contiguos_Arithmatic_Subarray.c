#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d ", &arr[i]);

    int ans = 2;
    int previous_difference = arr[1] - arr[0];
    int current = 2;
    int i = 2;
    while (i < n)
    {
        if (previous_difference == arr[i] - arr[i - 1])
            current++;
        else
        {
            previous_difference = arr[i] - arr[i - 1];
            current = 2;
        }
        ans = current>ans ? current : ans;
        i++;
    }

    printf("%d", ans);

    return 0;
}