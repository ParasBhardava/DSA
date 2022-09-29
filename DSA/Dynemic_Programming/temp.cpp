#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int bitmask, int n, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    if (idx == n)
        return 0;

    if (dp[idx][bitmask] != -1)
        return dp[idx][bitmask];

    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if ((bitmask & (1 << i)) == 0)
        {
            int ans = arr[idx][i] + solve(idx + 1, bitmask | (1 << i), n, arr, dp);
            mini = min(ans, mini);
        }
    }

    return dp[idx][bitmask] = mini;
}

int main()
{
    int n = 4;
    vector<vector<int>> arr = {{9, 2, 7, 8},
                               {6, 4, 3, 7},
                               {5, 8, 1, 8},
                               {7, 5, 9, 4}};

    vector<vector<int>> dp(n, vector<int>(16, -1));

    cout << solve(0, 0, n, arr, dp);

    return 0;
}