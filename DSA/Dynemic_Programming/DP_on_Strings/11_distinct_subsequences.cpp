#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{

    if (j < 0)
        return 1;

    if (i < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = solve(i - 1, j - 1, s1, s2, dp) + solve(i - 1, j, s1, s2, dp);

    else
        return dp[i][j] = solve(i - 1, j, s1, s2, dp);
}

int main()
{
    string s1 = "babgbag", s2 = "bag";
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << solve(n - 1, m - 1, s1, s2, dp) << "\n";

    return 0;
}