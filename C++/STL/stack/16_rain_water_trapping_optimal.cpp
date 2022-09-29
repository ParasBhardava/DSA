#include<bits/stdc++.h>
using namespace std;

int rainWaterTrapping(vector<int>&arr)
{
    int n = arr.size();
    int left = 0;
    int right  = n - 1;
    int maxLeft = 0, maxRight = 0;
    int res = 0;

    while(left <= right)
    {
        if(arr[left] <= arr[right])
        {
            if(arr[left] >= maxLeft)
                maxLeft = arr[left];

            else
                res += maxLeft - arr[left];

            left++;
        }

        else
        {
            if(arr[right] >= maxRight)
                maxRight = arr[right];

            else
                res += maxRight - arr[right];

            right--; 
        }
    }

    return res;
}

int main()
{
    vector<int>v{3, 0, 0, 2, 0, 4};
    cout<<rainWaterTrapping(v);

    return 0;
}

/*
                                    4
                3                   |
                |           2       |
                |           |       |
                |   0   0   |   0   |  

index:          0   1   2   3   4   5

*/