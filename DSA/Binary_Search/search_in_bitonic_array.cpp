#include<bits/stdc++.h>
using namespace std;

int maxElement(int arr[], int start, int end, int size)
{
    while(start <= end)
    {
        int mid = end + ((start-end)/2);

        if(mid > 0 && mid < size-1)
        {
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
                return mid; 

        else if(arr[mid-1] > arr[mid])
            end = end-1;

        else
            start = start+1;

        }

        else if(mid == 0)
        {
            if(arr[0] > arr[1])
                return 0;
                
            else
                return 1;
        }
        
        else if(mid == size-1)
        {
            if(arr[size-1] > arr[size-2])
                return size-1;
                
            else
                return size-2;
        }
    }

    return -1;
}

int binarySearchSorted(int arr[], int start, int end, int val)
{
    while(start <= end)
    {
        int mid = end + ((start-end)/2);
        if(arr[mid] == val)
            return mid;

        else if(arr[mid] < val)
            start = mid+1;

        else
            end = mid-1;
    }

    return -1;
}

int binarySearchReverseSorted(int arr[], int start, int end, int val)
{
    while(start <= end)
    {
        int mid = end + ((start-end)/2);
        if(arr[mid] == val)
            return mid;

        else if(arr[mid] > val)
            start = mid+1;

        else
            end = mid-1;
    }

    return -1;
}

int main()
{
    int n = 7;
    int arr[] = {-3, 9, 8, 20, 17, 5, 1};
    int start = 0, end = 6, val= 20;

    int maxIndex = maxElement(arr, start, end, n);
    int ans = binarySearchSorted(arr, start, maxIndex-1, val);

    if(ans != -1)
        cout<<ans<<"\n";

    else
    {
        ans = binarySearchReverseSorted(arr, maxIndex, end, val);
        cout<<ans<<"\n";
    }


    return 0;
}


// An array is said to  be bitonic if it has an increasing sequence of integers followed immediately by a decreasing sequence of integers. 