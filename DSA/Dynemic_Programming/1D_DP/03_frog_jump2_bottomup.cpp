#include <bits/stdc++.h>
using namespace std;

int solve(int k, vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int minCost = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = dp[i - j] + abs(arr[i] - arr[i - j]);
                minCost = min(minCost, jump);
            }
        }

        dp[i] = minCost;
    }

    return dp[n - 1];
}

int main()
{
    int k = 3;
    vector<int> arr = {10, 30, 40, 50, 20};

    cout << solve(k, arr);

    return 0;
}