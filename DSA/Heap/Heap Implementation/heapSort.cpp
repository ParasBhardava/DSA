#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int size, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < size && arr[left] > arr[i])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n = 5;
    int arr[] = {4, 2, 8, 1, 19};

    heapSort(arr, n);
    for(int i = 0; i<n; i++)
        cout<<arr[i]<<" ";

    return 0;
}