#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int start, int end, int val)
{
    while(start <= end)
    {
        int mid = end + ((start-end)/2);
        if(arr[mid] == val)
        {
            return (arr[mid]-val);
        }

        else if(arr[mid] < val)
            start = mid+1;
    
        else
            end = mid-1;
    }

    return min(abs(arr[start]-val), abs(arr[end]-val));
}


int main()
{
    int arr[] = {4, 6, 10};
    int start = 0, end = 2, val = 7;

    cout<<binarySearch(arr, start, end, val)<<"\n";

    return 0;
}
