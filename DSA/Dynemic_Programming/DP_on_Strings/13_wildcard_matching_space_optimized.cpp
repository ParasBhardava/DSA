/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 */

#include <bits/stdc++.h>
using namespace std;

bool solve(string &s, string &p)
{
    int n = s.size(), m = p.size();
    vector<bool> prev(m + 1, false);

    prev[0] = true;

    for (int j = 1; j <= m; j++)
    {
        bool flag = true;
        for (int jj = 1; jj <= j; j++)
        {
            if (p[jj - 1] != '*')
            {
                flag = false;
                break;
            }
        }

        prev[j] = flag;
    }

    for (int i = 1; i <= n; i++)
    {
        bool ele = prev[0];
        prev[0] = false;
        for (int j = 1; j <= m; j++)
        {
            bool temp = prev[j];

            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                prev[j] = ele;

            else if (p[j - 1] == '*')
                prev[j] = prev[j - 1] | prev[j];

            else
                prev[j] = false;

            ele = temp;
        }
    }

    return prev[m];
}

int main()
{
    string s = "abdefcd", p = "ab*cd";
    int n = s.size(), m = p.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << solve(s, p);
    return 0;
}