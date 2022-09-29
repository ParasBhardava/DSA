#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0, idx;

    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];

                if (dp[i][j] > ans)
                {
                    ans = dp[i][j];
                    idx = i;
                }
            }

            else
                dp[i][j] = 0;
        }
    }

    cout << s1.substr(idx - ans, ans) << "\n";
    return ans;
}

int main()
{
    string s1 = "GeeksforGeeks";
    int n = s1.size();
    string s2 = "GeeksQuiz";
    int m = s2.size();

    cout << longestSubstring(s1, s2);

    return 0;
}