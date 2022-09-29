#include <bits/stdc++.h>
using namespace std;

int LCS(string str, int n)
{
    string str1 = str;
    reverse(str.begin(), str.end());
    string str2 = str;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n + 1; i++)
        dp[0][i] = 0;

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    return dp[n][n];
}

int main()
{
    string str = "agbcba";
    int n = str.size();

    cout << LCS(str, n);

    return 0;
}