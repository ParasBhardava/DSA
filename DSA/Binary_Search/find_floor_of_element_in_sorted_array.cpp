#include<bits/stdc++.h>
using namespace std;

int floor(int arr[], int start, int end, int val)
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
            ans = arr[mid];
            start = mid+1;
        }

        else if(arr[mid] > val)
        {
            end= mid-1;
        }
    }

    return ans;

}

int main()
{
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int start = 0, end = 6, val = 19;
    int f = floor(arr, start, end, val);

    cout<<f<<"\n";
    return 0;
}