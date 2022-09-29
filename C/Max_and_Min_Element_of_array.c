#include<stdio.h>
#include<limits.h>

int main()
{
    int size;
    int max = INT_MIN;
    int min = INT_MAX;

    scanf("%d", &size);
    int arr[size];

    for(int i = 0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }

    for(int i = 0; i<size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
       

        if(arr[i] < min)
        {
            min = arr[i];   
        }
    }

    printf("%d\n", max);
    printf("%d", min);

    return 0;
}