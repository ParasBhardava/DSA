#include <bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[], int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < n && arr[left] > arr[i])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

int main()
{
    int n = 8;
    int arr[] = {3, 6, 5, 0, 8, 2, 1, 9};

    for(int i = 0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";

    for (int i = (n / 2) - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for(int i = 0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";

 
    return 0;
}