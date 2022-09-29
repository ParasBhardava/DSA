#include <bits/stdc++.h>
using namespace std;

int minCoins(int n, int sum, vector<int> &coins)
{

    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    for (int j = 0; j <= sum; j++)
    {
        if (j % coins[0] == 0)
            dp[0][j] = j / coins[0];

        else
            dp[0][j] = INT_MAX - 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            int dontTake = dp[i - 1][j];

            int take = INT_MAX - 1;
            if (coins[i] <= j)
                take = 1 + dp[i][j - coins[i]];

            dp[i][j] = min(take, dontTake);
        }
    }

    return dp[n - 1][sum];
}

int main()
{
    int n = 3;
    vector<int> coins = {25, 10, 5};
    int sum = 30;

    cout << minCoins(n, sum, coins) << "\n";

    return 0;
}
