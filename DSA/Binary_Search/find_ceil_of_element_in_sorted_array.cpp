#include<bits/stdc++.h>
using namespace std;

int ceil(int arr[], int start, int end, int val)
{
    int ans= -1;
    while(start<=end)
    {
        int mid = end + ((start-end)/2);

        if(arr[mid] == val)
        {
            ans = arr[mid];
            break;
        }

        else if(arr[mid] < val)
        {
           start = mid+1;
        }

        else
        {
            ans = arr[mid];
            end= mid-1;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int start = 0, end = 6, val = 20;
    int c = ceil(arr, start, end, val);

    cout<<c<<"\n";
    return 0;
}