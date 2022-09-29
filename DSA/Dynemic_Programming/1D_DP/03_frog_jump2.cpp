#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int k, vector<int> &arr, vector<int> &dp)
{
    if (idx == 0)
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    int minCost = INT_MAX;

    for (int j = 1; j <= k; j++)
    {
        if (idx - j >= 0)
        {
            int jump = solve(idx - j, k, arr, dp) + abs(arr[idx] - arr[idx - j]);
            minCost = min(minCost, jump);
        }
    }

    return dp[idx] = minCost;
}

int main()
{
    int k = 3;
    vector<int> arr = {10, 30, 40, 50, 20};

    int n = arr.size();
    vector<int> dp(n, -1);

    cout << solve(n - 1, k, arr, dp);

    return 0;
}