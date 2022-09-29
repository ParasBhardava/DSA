#include <bits/stdc++.h>
using namespace std;

int solve(string str, int n)
{
    int t[n][n];
    memset(t, 0, sizeof(t));

    int start = 1, maxLen = 1;
    for (int i = 0; i < n; i++)
        t[i][i] = 1;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == str[i + 1])
        {
            t[i][i + 1] = 1;
            start = i;
            maxLen = 2;
        }
    }

    // k is length of substring
    for (int k = 3; k <= n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1;

            if (str[i] == str[j] && t[i + 1][j - 1] == 1)
            {
                t[i][j] = 1;

                if (k > maxLen)
                {
                    maxLen = k;
                    start = i;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << t[i][j] << " ";
        }
        cout << "\n";
    }

    cout << str.substr(start, maxLen) << "\n";

    return maxLen;
}

int main()
{
    string str = "babad";
    int n = str.size();

    cout << solve(str, n) << "\n";

    return 0;
}