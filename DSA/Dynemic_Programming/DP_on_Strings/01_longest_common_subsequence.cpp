#include <bits/stdc++.h>
using namespace std;

int LCS(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = 1 + LCS(i - 1, j - 1, s1, s2, dp);

    else
        return dp[i][j] = max(LCS(i, j - 1, s1, s2, dp), LCS(i - 1, j, s1, s2, dp));
}

int main()
{
    string s1 = "abcdgh";
    int n = s1.size();
    string s2 = "abedfhr";
    int m = s2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << LCS(n - 1, m - 1, s1, s2, dp) << "\n";
    return 0;
}