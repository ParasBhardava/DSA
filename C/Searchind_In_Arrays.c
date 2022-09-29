#include <stdio.h>

int main()
{
    int n, target;
    scanf("%d %d", &n, &target);
    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int low = 0, high = n - 1, mid, found = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            found = 1;
            break;
        }

        else if (arr[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    if (found == 1)
    {
        printf("Target element found at %d", mid);
    }
    else
    {
        printf("Target element not found");
    }

    return 0;
}