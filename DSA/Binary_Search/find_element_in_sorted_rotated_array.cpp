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
    int arr[] = {11, 12, 15, 18, 2, 5, 6, 8};
    int start = 0, end = 7, n = 8;

    int mid, next, prev;
    while(start<=end)
    {
        mid = end + ((start-end)/2);
        next = (mid+1)%n;
        prev = (mid-1+n)%n;

        if(arr[mid] <= arr[prev] && arr[mid] <= arr[next])
        {
            break;
        }

        if(arr[start] <= arr[mid])
            start = mid+1;

        else if(arr[mid] <= arr[end])
            end = mid-1;

    }

    cout<<mid<<"\n";

    int ans = binarySearch(arr, 0, mid-1, 6);
    
    if(ans != -1)
        cout<<ans<<"\n";

    else 
    {
        ans = binarySearch(arr, mid, 7, 6);
        cout<<ans<<"\n";
    }

    return 0;
}
