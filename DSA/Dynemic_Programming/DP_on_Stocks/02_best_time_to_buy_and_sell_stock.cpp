/*

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 */

#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int buy, vector<int> &prices, vector<vector<int>> &dp)
{
    if (idx == prices.size())
        return 0;

    if (dp[idx][buy] != -1)
        return dp[idx][buy];

    int profit = 0;

    if (buy == 1)
    {
        profit = max(-prices[idx] + solve(idx + 1, 0, prices, dp),
                     solve(idx + 1, 1, prices, dp));
    }

    else
    {
        profit = max(prices[idx] + solve(idx + 1, 1, prices, dp),
                     solve(idx + 1, 0, prices, dp));
    }

    return dp[idx][buy] = profit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // vector<int> prices = {1, 3, 2, 8, 4, 9};

    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout << solve(0, 1, prices, dp);

    return 0;
}