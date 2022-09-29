/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int transaction, vector<int> &prices, int k, vector<vector<int>> &dp)
{
    if (idx >= prices.size() || transaction == 2 * k)
        return 0;

    if (dp[idx][transaction] != -1)
        return dp[idx][transaction];

    if (transaction % 2 == 0) // this means buy
    {
        return dp[idx][transaction] = max(-prices[idx] + solve(idx + 1, transaction + 1, prices, k, dp),
                                          solve(idx + 1, transaction, prices, k, dp));
    }

    else // sell
    {
        return dp[idx][transaction] = max(prices[idx] + solve(idx + 1, transaction + 1, prices, k, dp),
                                          solve(idx + 1, transaction, prices, k, dp));
    }
}

int solve(vector<int> &prices, int k)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int transaction = 2 * k - 1; transaction >= 0; transaction--)
        {
            if (transaction % 2 == 0) // this means buy
            {
                dp[idx][transaction] = max(-prices[idx] + dp[idx + 1][transaction + 1],
                                           dp[idx + 1][transaction]);
            }

            else // sell
            {
                dp[idx][transaction] = max(prices[idx] + dp[idx + 1][transaction + 1],
                                           dp[idx + 1][transaction]);
            }
        }
    }

    return dp[0][0];
}

int solveSpaceOptimized(vector<int> &prices, int k)
{
    int n = prices.size();
    vector<int> ahead(2 * k + 1, 0);
    vector<int> curr(2 * k + 1, 0);

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int transaction = 2 * k - 1; transaction >= 0; transaction--)
        {
            if (transaction % 2 == 0) // this means buy
            {
                curr[transaction] = max(-prices[idx] + ahead[transaction + 1],
                                        ahead[transaction]);
            }

            else // sell
            {
                curr[transaction] = max(prices[idx] + ahead[transaction + 1],
                                        ahead[transaction]);
            }
        }

        ahead = curr;
    }

    return ahead[0];
}

int main()
{
    int k = 2;
    vector<int> prices = {3, 2, 6, 5, 0, 3};

    cout << solve(prices, k) << "\n";
    cout << solveSpaceOptimized(prices, k) << "\n";
    return 0;
}

// we have 4 transaction maximum
// 0 1 2 3
// B S B S
