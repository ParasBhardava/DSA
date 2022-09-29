// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night. Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);
    dp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {

        int take = arr[i];
        if (i > 1)
            take += dp[i - 2];

        int dontTake = dp[i - 1];

        dp[i] = max(take, dontTake);
    }

    return dp[n - 1];
}

int main()
{
    vector<int> arr = {1, 2, 3, 1};
    cout << solve(arr);

    return 0;
}