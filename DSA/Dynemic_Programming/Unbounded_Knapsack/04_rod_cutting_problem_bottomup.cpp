#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &price)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = j * price[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int dontTake = dp[i - 1][j];

            int take = INT_MIN;
            int currLenght = i + 1;
            if (j - currLenght >= 0)
                take = price[i] + dp[i][j - currLenght];

            dp[i][j] = max(take, dontTake);
        }
    }

    return dp[n - 1][n];
}

int main()
{
    int n = 8;
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << solve(n, price);

    return 0;
}