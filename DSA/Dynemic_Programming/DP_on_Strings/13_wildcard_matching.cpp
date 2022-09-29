/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 */

#include <bits/stdc++.h>
using namespace std;

bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0)
        return true;

    if (j < 0 && i >= 0)
        return false;

    if (i < 0 && j >= 0)
    {
        for (int jj = 0; jj <= j; jj++)
        {
            if (p[jj] != '*')
                return false;
        }

        return true;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == p[j] || p[j] == '?')
        return dp[i][j] = solve(i - 1, j - 1, s, p, dp);

    if (p[j] == '*')
        return dp[i][j] = solve(i, j - 1, s, p, dp) | solve(i - 1, j, s, p, dp);

    return dp[i][j] = false;
}

int main()
{
    string s = "abdefcd", p = "ab*cd";
    int n = s.size(), m = p.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << solve(n - 1, m - 1, s, p, dp);
    return 0;
}