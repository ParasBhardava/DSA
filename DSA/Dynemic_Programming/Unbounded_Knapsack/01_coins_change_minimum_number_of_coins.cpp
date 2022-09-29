#include <bits/stdc++.h>
using namespace std;

int minCoins(int idx, int sum, vector<int> &coins, vector<vector<int>> &dp)
{

    if (idx == 0)
    {
        if (sum % coins[0] == 0)
            return sum / coins[0];

        return INT_MAX - 1;
    }

    if (dp[idx][sum] != -1)
        return dp[idx][sum];

    int dontTake = minCoins(idx - 1, sum, coins, dp);

    int take = INT_MAX - 1;
    if (coins[idx] <= sum)
        take = 1 + minCoins(idx, sum - coins[idx], coins, dp);

    return dp[idx][sum] = min(take, dontTake);
}

int main()
{
    int n = 3;
    vector<int> coins = {25, 10, 5};
    int sum = 30;
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

    cout << minCoins(n - 1, sum, coins, dp) << "\n";
    cout << INT_MIN << " " << INT_MAX + 1;
    return 0;
}