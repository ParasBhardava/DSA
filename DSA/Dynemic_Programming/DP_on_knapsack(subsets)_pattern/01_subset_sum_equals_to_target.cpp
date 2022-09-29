// You are given an array/list ‘arr’ of ‘N’ positive integers and an integer ‘k’. Your task is to check if there exists a subset in ‘arr’ with a sum equal to ‘k’. Note: Return true if there exists a subset with sum equal to ‘k’. Otherwise, return false.

#include <bits/stdc++.h>
using namespace std;

bool solve(int idx, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;

    if (idx == 0)
        return (arr[0] == target);

    if (dp[idx][target] != -1)
        return dp[idx][target];

    bool take = false;
    if (target >= arr[idx])
        take = solve(idx - 1, target - arr[idx], arr, dp);

    bool dontTake = solve(idx - 1, target, arr, dp);

    return dp[idx][target] = take | dontTake;
}

int main()
{
    int k = 4;
    vector<int> arr = {2, 5, 1, 6, 7};

    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    cout << solve(n - 1, k, arr, dp);

    return 0;
}