// only for distinct elements

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {11,12,15,18,2,5,6,8};
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
            start = mid;

        else if(arr[mid] <= arr[end])
            end = mid;

    }

    cout<<mid<<"\n";

    return 0;
}