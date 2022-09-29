#include <stdio.h>

void SELECTON_SORT(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);   
}

void BUBBLE_SORT(int arr[], int size)
{
    int counter = 1;
    while(counter<size)
    {
        for(int i=0; i<size-counter; i++)
        {
            if(arr[i] > arr[i+1])
            {
                int temp = arr[i+1];
                arr[i+1] =  arr[i];
                arr[i] = temp;
            }
        }
        counter++;
    }

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void INSERTION_SORT(int arr[], int size)
{
    for(int i=1; i<size; i++)
    {
        int current =  arr[i];
        int j =i-1;
        while(arr[j]>current && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int size;
    scanf("%d", &size);
    int arr[size];
    for(int i=0; i<size; i++)
    scanf("%d ", &arr[i]);

    SELECTON_SORT(arr, size);
    BUBBLE_SORT(arr, size);
    INSERTION_SORT(arr, size);

    return 0;
}