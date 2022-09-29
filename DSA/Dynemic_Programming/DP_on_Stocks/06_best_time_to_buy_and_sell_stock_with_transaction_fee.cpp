/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

#include <bits/stdc++.h>
using namespace std;

// small veriation of best time to buy and sell stock 2
int solve(vector<int> &prices, int fee)
{
    int n = prices.size();

    vector<int> ahead(2, 0);
    vector<int> curr(2, 0);
    ahead[0] = ahead[1] = 0;

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;

            if (buy == 1) // buy
            {
                profit = max(-prices[idx] + ahead[0],
                             ahead[1]);
            }

            else // sell
            {
                profit = max(prices[idx] - fee + ahead[1],
                             ahead[0]);
            }

            curr[buy] = profit;
        }

        ahead = curr;
    }

    return ahead[1];
}

int main()
{
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    cout << solve(prices, fee) << "\n";
    return 0;
}