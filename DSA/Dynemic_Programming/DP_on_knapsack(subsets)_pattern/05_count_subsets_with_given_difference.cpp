#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int sum, vector<int> &arr, vector<vector<int>> &dp)
{

    if (idx == 0)
    {
        if (sum == 0 && arr[0] == 0)
            return 2;

        if (sum == 0 || sum == arr[0])
            return 1;

        return 0;
    }
    if (dp[idx][sum] != -1)
        return dp[idx][sum];

    int dontTake = solve(idx - 1, sum, arr, dp);
    int take = 0;

    if (arr[idx] <= sum)
        take = solve(idx - 1, sum - arr[idx], arr, dp);

    return dp[idx][sum] = (take + dontTake);
}

int main()
{
    int n = 4;
    vector<int> arr = {5, 2, 6, 4};
    int diff = 3;

    int sum = accumulate(arr.begin(), arr.end(), 0);
    int ans;
    if (sum - diff < 0 || (sum - diff) % 2 == 1)
        ans = 0;

    else
    {
        vector<vector<int>> dp(n, vector<int>(((sum - diff) / 2) + 1, -1));
        ans = solve(n - 1, (sum - diff) / 2, arr, dp);
    }

    cout << ans << "\n";

    return 0;
}