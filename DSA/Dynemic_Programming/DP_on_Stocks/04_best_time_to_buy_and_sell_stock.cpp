/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices, int k)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
    vector<vector<int>> curr(2, vector<int>(k + 1, 0));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= k; cap++)
            {
                if (buy == 1)
                {
                    curr[buy][cap] = max(-prices[idx] + ahead[0][cap],
                                         ahead[1][cap]);
                }

                else
                {
                    curr[buy][cap] = max(prices[idx] + ahead[1][cap - 1],
                                         ahead[0][cap]);
                }
            }
        }

        ahead = curr;
    }

    return ahead[1][k];
}

int main()
{
    int k = 2;
    vector<int> prices = {3, 2, 6, 5, 0, 3};

    cout << solve(prices, k) << "\n";
    return 0;
}
