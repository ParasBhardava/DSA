#include<bits/stdc++.h>
using namespace std;

int lower_bound(int arr[], int n, int element)
{
    int left = 0, right = n-1;
    while(right - left > 1)
    {
        int mid = (left+right)/2;
        if(arr[mid] < element)
            left = mid+1;

        else
            right = mid;
    }

    if(arr[left] >= element)
        return left;
    
    if(arr[right] >= element)
        return right;

    return -1;    
}

int upper_bound(int arr[], int n, int element)
{
    int left = 0, right = n-1;
    while(right - left > 1)
    {
        int mid = (left+right)/2;
        if(arr[mid] <= element)
            left = mid+1;

        else
            right = mid;
    }

    if(arr[left] > element)
        return left;
    
    if(arr[right] > element)
        return right;

    return -1;    
}

int main()
{
    int n = 6;
    int arr[n] = {2, 3, 4, 6, 7, 8};
    int lb = lower_bound(arr, n, 9);
    cout<<lb<<" "<<arr[lb]<<"\n";
    int ub = upper_bound(arr, n, 8);
    cout<<ub<<" "<<arr[ub]<<"\n";
    return 0;
}