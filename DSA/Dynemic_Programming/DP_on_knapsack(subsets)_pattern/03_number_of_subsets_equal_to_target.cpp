#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int sum, vector<int> &arr, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;

    if (idx == 0)
        return arr[0] == sum;

    if (dp[idx][sum] != -1)
        return dp[idx][sum];

    int dontTake = solve(idx - 1, sum, arr, dp);
    int take = 0;

    if (arr[idx] <= sum)
        take = solve(idx - 1, sum - arr[idx], arr, dp);

    return dp[idx][sum] = (take + dontTake);
}

int main()
{
    int n = 4;
    vector<int> arr = {1, 2, 3, 3};
    int sum = 6;

    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    cout << solve(n - 1, sum, arr, dp) << "\n";
    return 0;
}