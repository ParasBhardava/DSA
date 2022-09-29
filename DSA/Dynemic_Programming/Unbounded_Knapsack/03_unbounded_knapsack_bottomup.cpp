#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wet)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    for (int j = 0; j <= W; j++)
    {
        dp[0][j] = ((int)(j / wet[0])) * val[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            int dontTake = dp[i - 1][j];

            int take = 0;
            if (j - wet[i] >= 0)
                take = val[i] + dp[i][j - wet[i]];

            dp[i][j] = max(take, dontTake);
        }
    }

    return dp[n - 1][W];
}

int main()
{
    int n = 2;
    vector<int> wet = {1, 50};
    vector<int> val = {1, 30};
    int W = 100;

    cout << unboundedKnapsack(n, W, val, wet) << "\n";
    return 0;
}