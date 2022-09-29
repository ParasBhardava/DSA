#include <bits/stdc++.h>
using namespace std;

int solve(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<int> prev(m + 1, 0);
    prev[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (s1[i - 1] == s2[j - 1])
                prev[j] = prev[j - 1] + prev[j];

            // else
            //     prev[j] = prev[j];
        }
    }

    return prev[m];
}

int main()
{
    string s1 = "babgbag", s2 = "bag";
    cout << solve(s1, s2) << "\n";

    return 0;
}