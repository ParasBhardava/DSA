#include <bits/stdc++.h>
using namespace std;

int solve(string &word1, string &word2)
{
    int n = word1.size();
    int m = word2.size();

    vector<int> curr(m + 1, 0);
    vector<int> prev(m + 1, 0);

    for (int j = 0; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++)
    {
        curr[0] = i;
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
                curr[j] = prev[j - 1];

            else
            {
                int insert = 1 + curr[j - 1];
                int del = 1 + prev[j];
                int replace = 1 + prev[j - 1];

                curr[j] = min(replace, min(insert, del));
            }
        }

        prev = curr;
    }

    return prev[m];
}

// Most space optimized

int solve(string &word1, string &word2)
{
    int n = word1.size();
    int m = word2.size();

    vector<int> prev(m + 1, 0);

    for (int j = 0; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++)
    {
        int ele = prev[0];
        prev[0] = i;
        for (int j = 1; j <= m; j++)
        {
            int temp = prev[j];

            if (word1[i - 1] == word2[j - 1])
                prev[j] = ele;

            else
            {
                int insert = 1 + prev[j - 1];
                int del = 1 + prev[j];
                int replace = 1 + ele;

                prev[j] = min(replace, min(insert, del));
            }

            ele = temp;
        }
    }

    return prev[m];
}

int main()
{
    // string word1 = "horse", word2 = "ros";
    string word1 = "intention", word2 = "execution";
    int n = word1.size();
    int m = word2.size();

    cout << solve(word1, word2);

    return 0;
}