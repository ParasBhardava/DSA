/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    // Everything bydefault is zero
    // so no need to write  basecase

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy == 1)
            {
                dp[idx][buy] = max(-prices[idx] + dp[idx + 1][0],
                                   dp[idx + 1][1]);
            }

            else
            {
                dp[idx][buy] = max(prices[idx] + dp[idx + 2][1],
                                   dp[idx + 1][0]);
            }
        }
    }

    return dp[0][1];
}

int main()
{
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << solve(prices) << "\n";
    return 0;
}