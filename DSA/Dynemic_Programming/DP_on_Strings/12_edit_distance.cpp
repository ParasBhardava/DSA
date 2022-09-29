#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;

    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (word1[i] == word2[j])
        return dp[i][j] = solve(i - 1, j - 1, word1, word2, dp);

    else
    {
        int insert = 1 + solve(i, j - 1, word1, word2, dp);
        int del = 1 + solve(i - 1, j, word1, word2, dp);
        int replace = 1 + solve(i - 1, j - 1, word1, word2, dp);

        return dp[i][j] = min(replace, min(insert, del));
    }
}

int main()
{
    string word1 = "horse", word2 = "ros";
    int n = word1.size();
    int m = word2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << solve(n - 1, m - 1, word1, word2, dp);

    return 0;
}