// In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair. Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.

#include <bits/stdc++.h>
using namespace std;

int solve(int idx, vector<int> &arr, vector<int> &dp)
{
    if (idx == 0)
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    int left = abs(arr[idx] - arr[idx - 1]) + solve(idx - 1, arr, dp);
    int right = INT_MAX;

    if (idx > 1)
        right = abs(arr[idx] - arr[idx - 2]) + solve(idx - 2, arr, dp);

    return dp[idx] = min(left, right);
}

int main()
{
    vector<int> arr = {10, 20, 30, 10};

    int n = arr.size();
    vector<int> dp(n, -1);

    cout << solve(n - 1, arr, dp);
    return 0;
}