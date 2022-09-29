#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE 10

void insertAtFirst(int arr[], int *size, int element)
{
    if((*size) >= MAXSIZE)
    {
        printf("Size is Exceed !\n");
        exit(0);
    }

    int i;
    for (i = *size; i > 0; i--)
    {
        arr[i] = arr[i-1];
    }

    arr[i] = element;
    (*size)++;
}

void insertAtLast(int arr[], int *size, int elelment)
{
    if((*size) >= MAXSIZE)
    {
        printf("Size is Exceed !\n");
        exit(0);
    }

    arr[*size] = elelment;
    (*size)++;
}

void insertAtIndex(int arr[], int *size, int element, int index)
{
    if(index < 0 && index >(*size))
    {
        printf("Invalid Index\n");
        return;
    }
    int i;
    for (i = (*size); i > index; i--)
    {
        arr[i] = arr[i-1];
    }

    arr[i] = element;
    (*size)++;

}

int min(int arr[], int *size)
{
    if((*size) == 0)
    {
        printf("Array is empty !\n");
        return 0;
    }

    int minimum = __INT_MAX__;
    for(int i=0; i<(*size); i++)
    {
        if(arr[i] < minimum)
            minimum = arr[i];
    }

    return minimum;
}

int max(int arr[], int *size)
{
    if((*size) == 0)
    {
        printf("Array is empty !\n");
        return 0;
    }

    int maximum = -100000000;
    for(int i=0; i<(*size); i++)
    {
        if(arr[i] > maximum)
            maximum = arr[i];
    }

    return maximum;
}

int search(int arr[], int *size, int element)
{
    if((*size) == 0)
    {
        printf("Array is empty !\n");
        return 0;
    }

    int ans = 0;
    for(int i=0; i<(*size); i++)
    {
        if(arr[i] == element)
        {
            ans = 1;
            break;
        }
    }
    
    return ans;

}

void display(int arr[], int *size)
{
    if((*size) == 0)
        printf("Array is empty !\n");


    for(int i=0; i<(*size); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void reverse(int arr[], int *size)
{
    if((*size) == 0)
        printf("Array is empty !\n");

    for(int i=(*size)-1; i>=0; i--)
        printf("%d ", arr[i]);
    printf("\n");
        
}

int main()
{
    int arr[MAXSIZE] = {1, 2, 3};
    int size = 3;
    display(arr, &size);

    insertAtFirst(arr, &size, 7);
    display(arr, &size);

    insertAtLast(arr, &size, 5);
    display(arr, &size);
    
    insertAtIndex(arr, &size, 8, 2);
    display(arr, &size);
    
    reverse(arr, &size);
    
    printf("Minimum element is %d\n", min(arr, &size));
    printf("Maximum element is %d\n", max(arr, &size));
    
    int element = 2;
    if(search(arr, &size, element))
        printf("%d present in the array\n", element);
    else    
        printf("%d is not present in the array\n", element);

    return 0;
}
