#include<bits/stdc++.h>
using namespace std;

int firstOccurence(int arr[], int start, int end, int val)
{
    int ans = -1;
    while(start<=end)
    {
        int mid = end+((start-end)/2);
        if(arr[mid] == val)
        {
            ans = mid;
            end = mid-1;
        }

        else if(arr[mid]>val)
            end = mid-1;

        else
            start = mid+1;
    }

    return ans;
}

int lastOccurence(int arr[], int start, int end, int val)
{
    int ans = -1;
    while(start<=end)
    {
        int mid = end+((start-end)/2);
        if(arr[mid] == val)
        {
            ans = mid;
            start = mid+1;
        }

        else if(arr[mid]>val)
            end = mid-1;

        else
            start = mid+1;
    }

    return ans;
}

int main()
{
    int arr[] = {2, 4, 10, 10, 10, 18, 20};
    int end = 6, start = 0, count = 0;

    int first = firstOccurence(arr, start, end, 10);
    int last = lastOccurence(arr, start, end, 10);

    cout<<last-first+1<<"\n";

    return 0;
}