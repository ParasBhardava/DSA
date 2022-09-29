#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void sort_integer_array(int arr[], int n)
{
    printf("%d\n", n);
    for(int i = 0; i<n-1; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    
    for(int i = 0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int size;
    scanf("%d", &size);
    int integer_array[size];
    
    for(int i = 0; i<size; i++)
    {
        scanf("%d ", &integer_array[i]);
    }
    
    sort_integer_array(integer_array, size);
    
    return 0;
}
