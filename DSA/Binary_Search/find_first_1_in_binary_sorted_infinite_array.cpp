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


int main()
{
    int arr[] = {0, 0, 1, 1, 1, 1};
    int start = 0, end = 1;

    while(1 > arr[end])
    {
        start = end;
        end = end*2;
    }

    cout<<firstOccurence(arr, start, end, 1)<<"\n";

    return 0;
}