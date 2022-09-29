#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int idx, int W, vector<int> &val, vector<int> &wet, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        return (W / wet[idx]) * val[idx];
    }

    if (dp[idx][W] != -1)
        return dp[idx][W];

    int dontTake = unboundedKnapsack(idx - 1, W, val, wet, dp);

    int take = 0;
    if (W - wet[idx] >= 0)
        take = val[idx] + unboundedKnapsack(idx, W - wet[idx], val, wet, dp);

    return dp[idx][W] = max(take, dontTake);
}

int main()
{
    int n = 2;
    vector<int> wet = {1, 50};
    vector<int> val = {1, 30};
    int W = 100;

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << unboundedKnapsack(n - 1, W, val, wet, dp) << "\n";
    return 0;
}