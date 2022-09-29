// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night. Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

#include <bits/stdc++.h>
using namespace std;

int solve(int idx, vector<int> &arr, vector<int> &dp)
{
    if (idx == 0)
        return arr[idx];

    if (idx < 0)
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    int take = arr[idx] + solve(idx - 2, arr, dp);
    int dontTake = solve(idx - 1, arr, dp);

    return dp[idx] = max(take, dontTake);
}

int main()
{
    vector<int> arr = {1, 2, 3, 1};

    int n = arr.size();
    vector<int> dp(n, -1);
    cout << solve(n - 1, arr, dp);

    return 0;
}