#include <bits/stdc++.h>
using namespace std;

int maxWays(int n, int sum, vector<int> &coins)
{
    vector<int> dp(sum + 1);

    for (int j = 0; j <= sum; j++)
        dp[j] = (j % coins[0] == 0);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j - coins[i] >= 0)
                dp[j] += dp[j - coins[i]];
        }
    }

    return dp[sum];
}

int main()
{
    int n = 3;
    vector<int> coins = {1, 2, 5};
    int sum = 5;
    cout << maxWays(n, sum, coins) << "\n";

    return 0;
}