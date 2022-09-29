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
    int arr[] = {1, 4, 8, 12, 15, 18, 20};
    int ans = binarySearch(arr, 0, 6, 15);

    cout<<ans<<"\n";

    return 0;
}