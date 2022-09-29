#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    for(int i = 0; i<n-1; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(arr[j] < arr[i])
                swap(arr[i], arr[j]);

        }
    }
}

void print(int arr[], int n)
{
    for(int i = 0; i<n; i++)
        cout<<arr[i]<<" ";
    
    cout<<"\n";
}

int main()
{
    int n = 7;
    int arr[7] = {1, 6, 2, 4, 5, 3, 5};

    insertionSort(arr, n);

    cout<<"Sorted Array : ";
    print(arr, n);

    return 0;
}

// No. of comparisons : 
// Worst case : n*(n - 1)/2        descending order
// Best case : n*(n - 1)/2        ascending order
// Average case : n*(n - 1)/2           

// swaps are always (n - 1)