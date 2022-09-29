#include <stdio.h>

int check_sorted(int arr[], int n)
{
    if (n == 1)
        return 1;

    return (arr[0] < arr[1] && check_sorted(arr+1, n-1));
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    printf("%d", check_sorted(arr, 5));
    return 0;
}