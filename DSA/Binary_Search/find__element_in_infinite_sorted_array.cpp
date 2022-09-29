#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int start, int end, int val)
{
    int ans = -1;
    while(start <= end)
    {
        int mid = end + ((start-end)/2);
        if(arr[mid] == val)
        {
            ans = mid;
            break;
        }

        else if(arr[mid] < val)
            start = mid+1;

        else
            end = mid-1;
    }

    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 14, 15, 16, 17, 18, 19};
    int start = 0, end = 1, val = 8;

    while(val > arr[end])
    {
        start = end;
        end = 2*end;

    }

    cout<<binarySearch(arr, start, end, val)<<"\n";

    return 0;
}