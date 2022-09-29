#include <stdio.h>

int Insert(int arr[], int *size, int maxSize, int element, int index)
{
    if (*size >= maxSize)
        return -1;

    for (int i = (*size - 1); i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    (*size)++;
    return 1;
}

int Delete(int arr[], int *size, int index)
{
    if (*size == 0)
        return -1;

    for (int i = index; i < (*size - 1); i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    return 1;
}

void getVal(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int arr[100] = {1, 2, 3, 6, 8, 9, 7};
    int size = 7, maxSize = 100, element = 45, index = 3;
    Insert(arr, &size, maxSize, element, index);
    getVal(arr, size);
    Delete(arr, &size, 2);
    getVal(arr, size);

    return 0;
}