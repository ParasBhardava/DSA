// you have N people and N jobs (N <= 20). Find the minimum cost by assigning job to each person

#include <bits/stdc++.h>
using namespace std;

int minCost(int day, int mask, int n, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    if (day > n)
        return 0;

    if (dp[day][mask] != -1)
        return dp[day][mask];

    int mini = INT_MAX;

    for (int person = 1; person <= n; day++)
    {
        if (mask & (1 << person))
        {
            mask = mask | (1 << person);
            mini = min(mini, arr[person][day] + minCost(day + 1, mask, n, arr, dp));
            mask = mask ^ (1 << person);
        }
    }

    return dp[day][mask] = mini;
}

int main()
{
    int n = 5;
    vector<vector<int>> dp(n, vector<int>(1 << 5, -1));
    return 0;
}