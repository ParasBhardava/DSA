#include <bits/stdc++.h>
using namespace std;

int solve(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int j = 1; j <= m; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][m];
}

int main()
{
    string s1 = "babgbag", s2 = "bag";
    cout << solve(s1, s2) << "\n";

    return 0;
}