#include <bits/stdc++.h>
using namespace std;

int solve(string &s)
{
    int n = s.size();
    vector<int> dp(n + 1, 0);
    int maxLen = 1;

    dp[n - 2] = 1;
    if (s[n - 2] == s[n - 1])
    {
        maxLen = 2;
        dp[n - 1] = 1;
    }

    for (int i = n - 3; i >= 0; i--)
    {
        dp[i] = 1;
        int ele = dp[i + 1];
        if (s[i] == s[i + 1])
        {
            dp[i + 1] = 1;
            maxLen = max(2, maxLen);
        }

        else
            dp[i + 1] = 0;

        for (int j = i + 2; j < n; j++)
        {
            int temp = dp[j];
            if (s[i] == s[j])
                dp[j] = ele;

            else
                dp[j] = 0;

            ele = temp;

            if (dp[j] == 1)
                maxLen = max(maxLen, j - i + 1);
        }
    }

    return maxLen;
}

int main()
{
    string s = "babad";
    cout << solve(s);

    return 0;
}
