#include <bits/stdc++.h>
using namespace std;
int maxCrossingSum(int arr[], int low, int mid, int high)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }
    return max(left_sum + right_sum, max(left_sum, right_sum));
}

int maxSubArraySum(int arr[], int low, int high)
{
    if (low == high)
        return arr[low];
    
    int mid = (low + high) / 2;
    return max(max(maxSubArraySum(arr, low,mid),maxSubArraySum(arr, mid + 1,high)), maxCrossingSum(arr, low, mid, high));
}

int main()
{
    int arr[] = {13, 3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15 - 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, 0, n - 1);
    cout<<"\n\n\n\n\n\n\n";
    cout << "Maximum sum of subarray is: " << max_sum<<"\n";

    cout<<"\n\n\n\n\n\n\n";
    return 0;
}
