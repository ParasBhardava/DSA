#include <bits/stdc++.h>
using namespace std;

int solve(int n, int sum, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;

    if (arr[0] <= sum)
        dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            int dontTake = dp[i - 1][j];
            int take = 0;

            if (arr[i] <= j)
                take = dp[i - 1][j - arr[i]];

            dp[i][j] = take + dontTake;
        }
    }

    return dp[n - 1][sum];
}

int main()
{
    int n = 4;
    vector<int> arr = {1, 2, 3, 3};
    int sum = 6;

    cout << solve(n, sum, arr) << "\n";
    return 0;
}