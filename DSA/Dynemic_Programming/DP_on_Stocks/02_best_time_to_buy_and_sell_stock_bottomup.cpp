/*

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 */

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    dp[n][0] = dp[n][1] = 0;
    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;

            if (buy == 1)
            {
                profit = max(-prices[idx] + dp[idx + 1][0],
                             dp[idx + 1][1]);
            }

            else
            {
                profit = max(prices[idx] + dp[idx + 1][1],
                             dp[idx + 1][0]);
            }

            dp[idx][buy] = profit;
        }
    }

    return dp[0][1];
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << solve(prices);

    return 0;
}