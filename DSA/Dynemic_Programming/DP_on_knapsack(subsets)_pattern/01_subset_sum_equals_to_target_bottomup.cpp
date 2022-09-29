// You are given an array/list ‘arr’ of ‘N’ positive integers and an integer ‘k’. Your task is to check if there exists a subset in ‘arr’ with a sum equal to ‘k’. Note: Return true if there exists a subset with sum equal to ‘k’. Otherwise, return false.

#include <bits/stdc++.h>
using namespace std;

bool solve(int target, vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for (int i = 0; i < n; i++)
        dp[i][0] = 1;

    dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool take = 0;
            if (j >= arr[i])
                take = dp[i - 1][j - arr[i]];

            bool dontTake = dp[i - 1][j];

            dp[i][j] = take | dontTake;
        }
    }

    return dp[n - 1][target];
}

int main()
{
    int k = 4;
    vector<int> arr = {2, 5, 1, 6, 7};
    int n = arr.size();

    cout << solve(k, arr);

    return 0;
}