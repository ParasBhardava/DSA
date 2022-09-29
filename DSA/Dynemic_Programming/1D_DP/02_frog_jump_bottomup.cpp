// In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair. Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr)
{

    int n = arr.size();
    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int fs = abs(arr[i] - arr[i - 1]) + dp[i - 1];
        int ss = INT_MAX;
        if (i > 1)
            ss = abs(arr[i] - arr[i - 2]) + dp[i - 2];

        dp[i] = min(fs, ss);
    }

    return dp[n - 1];
}

int main()
{
    vector<int> arr = {10, 20, 30, 10};
    cout << solve(arr);
    return 0;
}