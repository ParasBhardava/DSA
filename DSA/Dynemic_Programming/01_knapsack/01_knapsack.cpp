#include <bits/stdc++.h>
using namespace std;

int knapsack(int idx, int W, vector<int> &wet, vector<int> &val, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (wet[0] <= W)
            return val[0];

        else
            return 0;
    }

    if (dp[idx][W] != -1)
        return dp[idx][W];

    int take = INT_MIN;
    if (wet[idx] <= W)
        take = val[idx] + knapsack(idx - 1, W - wet[idx], wet, val, dp);

    int dontTake = knapsack(idx - 1, W, wet, val, dp);

    return dp[idx][W] = max(take, dontTake);
}

int main()
{
    int n = 3;
    vector<int> wet = {10, 20, 30};
    vector<int> val = {60, 100, 120};
    int W = 50;

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << knapsack(n - 1, W, wet, val, dp);

    return 0;
}