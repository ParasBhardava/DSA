#include <bits/stdc++.h>
using namespace std;

string printSCS(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    int dp[n + 1][m + 1];

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

    int i = n, j = m;
    string ans = "";

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans.push_back(s1[i - 1]);
            i--;
            j--;
        }

        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans.push_back(s1[i - 1]);
            i--;
        }

        else
        {
            ans.push_back(s2[j - 1]);
            j--;
        }
    }

    while (i > 0)
    {
        ans.push_back(s1[i - 1]);
        i--;
    }

    while (j > 0)
    {
        ans.push_back(s2[j - 1]);
        j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string str1 = "geek";
    int n = str1.size();
    string str2 = "eke";
    int m = str2.size();

    cout << printSCS(str1, str2) << "\n";
    return 0;
}