#include <bits/stdc++.h>
using namespace std;

int LCS(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < m + 1; i++)
        dp[0][i] = 0;

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    return m + n - dp[n][m];
}

int main()
{
    string str1 = "geek";
    int n = str1.size();
    string str2 = "eke";
    int m = str2.size();

    cout << LCS(str1, str2) << "\n";
    return 0;
}