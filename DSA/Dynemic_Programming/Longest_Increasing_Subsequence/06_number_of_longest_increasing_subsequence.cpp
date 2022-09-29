#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr)
{
    int n = arr.size();

    vector<int> dp(n, 1), count(n, 1);
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
            {
                dp[i] = 1 + dp[j];
                count[i] = count[j];
            }

            else if (arr[j] < arr[i] && 1 + dp[j] == dp[i])
            {
                count[i] += count[j];
            }
        }

        maxi = max(maxi, dp[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
            ans += count[i];
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 5, 4, 3, 2, 6, 7, 10, 8, 9};
    cout << solve(arr) << "\n";
    return 0;
}