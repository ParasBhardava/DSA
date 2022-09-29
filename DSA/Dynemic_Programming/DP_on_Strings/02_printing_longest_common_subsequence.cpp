#include <bits/stdc++.h>
using namespace std;

string LCS(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    int i = n, j = m;
    int size = dp[n][m], idx = size - 1;
    string ans(size, ' ');
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans[idx] = s1[i - 1];
            idx--;
            i--;
            j--;
        }

        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
                j--;

            else
                i--;
        }
    }

    return ans;
}

int main()
{
    string s1 = "abcdgh";
    string s2 = "abedfhr";
    string lcs = LCS(s1, s2);
    cout << "\n\n";
    cout << "lenght of Longest Common subsequence is : " << lcs.size() << "\n";
    cout << "Longest Common subsequence is : " << lcs << "\n";
    cout << "\n\n";
    return 0;
}