#include <bits/stdc++.h>
using namespace std;

bool solve(int sum, vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

    for (int i = 0; i < n; i++)
        dp[i][0] = 1;

    if (arr[0] <= sum)
        dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            bool take = 0;
            if (j >= arr[i])
                take = dp[i - 1][j - arr[i]];

            bool dontTake = dp[i - 1][j];

            dp[i][j] = take | dontTake;
        }
    }

    return dp[n - 1][sum];
}

int main()
{
    vector<int> arr = {1, 5, 11, 5};

    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    bool ans = false;
    if (sum % 2 == 0)
        ans = solve(sum / 2, arr);

    cout << ans << "\n";

    return 0;
}