#include<bits/stdc++.h>
using namespace std;

int minElement(int arr[], int n)
{
    int start = 0, end = n-1, mid;

    while(start < end)
    {
        int mid = start + (end-start)/2;
    
        if(arr[mid] > arr[end])
            start = mid + 1;
        
        else if(arr[mid] < arr[end])
            end = mid;

        else
            end--;
    }
    
    return start;
}

int main()
{
    int n = 8;
    int arr[] = {3,3,3,3,4,1,2,3};

    cout<<minElement(arr, n)<<"\n";
    return 0;
}