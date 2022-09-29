#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    for(int i = 1; i<n; i++)
    {
        int element = arr[i];
        int j = i-1;
        while(j > -1 && arr[j] > element)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = element;
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
    int arr[7] = {6, 12, 18, 20, 14, 8, 2};
    // int arr[7] = {1, 6, 2, 4, 5, 3, 5};

    insertionSort(arr, n);

    cout<<"Sorted Array : ";
    print(arr, n);


    return 0;
}

// No. of comparison :
// Worst case : n*(n-1)/2        descending order
// Best case : (n-1)             ascending order
// Average case : Bitween  (n-1) to n*(n-1)/2           
// put counter inside while loop
// then count + 1