#include<bits/stdc++.h>
using namespace std;

int peakElement(int arr[], int start, int end, int size)
{
    if(size == 1)
        return 0;

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
    int arr[] = {1, 2, 3, 1};
    int start = 0, end = 3, n = 4;

    cout<<peakElement(arr, start, end, n)<<"\n";

    return 0;
}

// A peak element is an element thatis greater than its neighbours 