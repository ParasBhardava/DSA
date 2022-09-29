// Largest Sum Contiguous Subarray

#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int> &arr)
{
    int n = arr.size();
    int maxSum = INT_MIN, sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxSum = max(maxSum, sum);

        if (sum < 0)
            sum = 0;
    }
    return maxSum;
}

int main()
{

    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << maxSubArraySum(arr);
    return 0;
}