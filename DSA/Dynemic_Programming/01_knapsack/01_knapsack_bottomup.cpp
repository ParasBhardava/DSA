#include <bits/stdc++.h>

using namespace std;

int knapsack(int n, int W, int wet[], int val[])
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    for (int j = wet[0]; j <= W; j++)
        dp[0][j] = val[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            int take = INT_MIN;
            if (wet[i] <= j)
                take = val[i] + dp[i - 1][j - wet[i]];

            int dontTake = dp[i - 1][j];

            dp[i][j] = max(take, dontTake);
        }
    }

    return dp[n - 1][W];
}

int main()
{
    int n = 3;
    int wet[] = {10, 20, 30};
    int val[] = {60, 100, 120};
    int W = 50;

    cout << "Total Value: " << knapsack(n, W, wet, val) << "\n";

    return 0;
}
