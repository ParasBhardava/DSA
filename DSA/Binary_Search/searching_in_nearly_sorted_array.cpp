#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int start, int end, int val)
{
    int ans = -1;
    while(start <= end)
    {
        int mid = end +  ((start-end)/2);
        if(arr[mid] == val)
        {
            ans = mid;
            break;
        }

        if(mid-1 >= start && arr[mid-1] == val)
        {
            ans = mid-1;
            break;
        }

        if(mid+1 <= end && arr[mid+1] == val)
        {
            ans = mid+1;
            break;
        }

        else if(arr[mid] < val)
            start = mid+2;

        else
            end = mid-2;
    }
    return ans;
}

int main()
{
    int arr[] = {10, 3, 40, 20, 50, 80, 70};

    int start = 0, end = 6, val = 40;
    int ans = search(arr, start, end, val);
    cout<<ans<<"\n";

    return 0;
}