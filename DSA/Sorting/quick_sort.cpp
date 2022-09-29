#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;

    for(int j = start; j < end; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i+1], arr[end]);
    return i+1;
}

void quickSort(int arr[], int start, int end)
{
    if(start < end)
    {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot-1);
        quickSort(arr, pivot + 1, end);
    }
}


int main()
{
    int n = 10;
    int arr[10] = {11, 13, 7, 12, 1, 9, 11, 5, 10, 3};
    
    for(auto &i : arr)
        cout<<i<<" ";
    cout<<"\n";

    quickSort(arr, 0, n-1);
    for(auto &i: arr)
        cout<<i<<" ";
    cout<<"\n";

    return 0;
}