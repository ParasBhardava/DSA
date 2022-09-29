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
    vector<vector<int>> ahead(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
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

    return ahead[1][2];
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

    cout << solve(prices) << "\n";
    return 0;
}
