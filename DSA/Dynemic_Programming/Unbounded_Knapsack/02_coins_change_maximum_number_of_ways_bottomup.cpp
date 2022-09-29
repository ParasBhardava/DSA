#include <bits/stdc++.h>
using namespace std;

int ways(int n, int sum, vector<int> &coins)
{
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    for (int j = 0; j <= sum; j++)
        dp[0][j] = (j % coins[0] == 0);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            int dontTake = dp[i - 1][j];

            int take = 0;
            if (coins[i] <= j)
                take = dp[i][j - coins[i]];

            dp[i][j] = take + dontTake;
        }
    }

    return dp[n - 1][sum];
}

int main()
{
    int n = 3;
    vector<int> coins = {1, 2, 3};
    int sum = 4;

    cout << ways(n, sum, coins) << "\n";
    return 0;
}