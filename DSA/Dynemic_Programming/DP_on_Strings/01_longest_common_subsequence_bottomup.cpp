#include <bits/stdc++.h>
using namespace std;

// IN bottomup(tabulation) we can not write base condition like this
// if (i < 0 || j < 0) return 0;
// because in array there is no negative indices
// so we shit every index by  +1;
// so base case become like this
// (i == 0 || j == 0) return 0;

int LCS(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    return dp[n][m];
}

int main()
{
    string s1 = "abcdgh";
    string s2 = "abedfhr";

    cout << LCS(s1, s2) << "\n";
    return 0;
}