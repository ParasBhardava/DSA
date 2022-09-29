#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int flag = 0;
    for(int i = 0; i < n-1 ; i++)
    {
        flag = 0;
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                flag = 1;
            }
        }

        if(flag == 0)
            break;
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
    int n = 10;
    int arr[10] = {11, 13, 7, 12, 1, 9, 24, 5, 10, 3};

    bubbleSort(arr, n);

    cout<<"Sorted Array : ";
    print(arr, n);

    return 0;
}