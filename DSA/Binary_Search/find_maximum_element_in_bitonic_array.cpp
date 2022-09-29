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

int main()
{
    int n = 5;
    int arr[] = {1, 4, 8, 3, 2};
    int  start = 0, end = 4;
    cout<<maxElement(arr, start, end, n);

    return 0;
}


// An array is said to  be bitonic if it has an increasing sequence of integers followed immediately by a decreasing sequence of integers. 