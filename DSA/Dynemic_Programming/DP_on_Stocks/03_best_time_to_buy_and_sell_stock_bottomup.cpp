/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    // We are not writing base cases because in base case we return 0 but in tabulation  by default all element of 3D array is zero, so no need to write base case

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if (buy == 1)
                {
                    dp[idx][buy][cap] = max(-prices[idx] + dp[idx + 1][0][cap],
                                            dp[idx + 1][1][cap]);
                }

                else
                {
                    dp[idx][buy][cap] = max(prices[idx] + dp[idx + 1][1][cap - 1],
                                            dp[idx + 1][0][cap]);
                }
            }
        }
    }

    return dp[0][1][2];
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

    cout << solve(prices) << "\n";
    return 0;
}
