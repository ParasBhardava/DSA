/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp)
{
    if (idx >= prices.size() || cap == 0)
        return 0;

    if (dp[idx][buy][cap] != -1)
        return dp[idx][buy][cap];

    if (buy == 1)
    {
        return dp[idx][buy][cap] = max(-prices[idx] + solve(idx + 1, 0, cap, prices, dp),
                                       solve(idx + 1, 1, cap, prices, dp));
    }

    else
    {
        return dp[idx][buy][cap] = max(prices[idx] + solve(idx + 1, 1, cap - 1, prices, dp),
                                       solve(idx + 1, 0, cap, prices, dp));
    }
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

    cout << solve(0, 1, 2, prices, dp) << "\n";
    return 0;
}
