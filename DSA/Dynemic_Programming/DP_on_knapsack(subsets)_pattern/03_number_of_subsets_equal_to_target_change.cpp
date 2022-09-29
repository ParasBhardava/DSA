#include <bits/stdc++.h>
using namespace std;

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
    int n = 3;
    vector<int> arr = {0, 0, 1};
    int sum = 1;

    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    cout << solve(n - 1, sum, arr, dp) << "\n";
    return 0;
}