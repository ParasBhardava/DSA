#include <bits/stdc++.h>
using namespace std;

int maxWays(int idx, int sum, vector<int> &coins, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        return (sum % coins[idx] == 0);
    }

    if (dp[idx][sum] != -1)
        return dp[idx][sum];

    int dontTake = maxWays(idx - 1, sum, coins, dp);

    int take = 0;
    if (coins[idx] <= sum)
        take = maxWays(idx, sum - coins[idx], coins, dp);

    return dp[idx][sum] = take + dontTake;
}

int main()
{
    int n = 3;
    vector<int> coins = {1, 2, 3};
    int sum = 4;

    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    cout << maxWays(n - 1, sum, coins, dp) << "\n";
    return 0;
}