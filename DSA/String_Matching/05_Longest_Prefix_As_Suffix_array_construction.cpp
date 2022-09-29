// KMP algo
// Prefix function

#include <bits/stdc++.h>
using namespace std;

// TC : O(N), using precomputation
vector<int> LPS(string &s)
{
    int n = s.size();
    int i = 1, len = 0;

    vector<int> lps(n, 0);

    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }

        else
        {
            if (len != 0)
                len = lps[len - 1];

            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

vector<int> KMP(string &s, string &pattern)
{
    int n1 = s.size();
    int n2 = pattern.size();

    vector<int> lps = LPS(pattern);
    vector<int> res;
    int i = 0, j = 0;
    while (i < n1)
    {
        if (s[i] == pattern[j])
        {
            i++;
            j++;
        }

        else
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }

        if (j == n2)
        {
            res.push_back(i - n2);
            j = lps[j - 1];
        }
    }

    return res;
}

int main()
{
    string s = "ababcabcabababd";
    string pattern = "ababd";

    vector<int> occurences = KMP(s, pattern);
    for (int it : occurences)
        cout << it << " ";

    return 0;
}

/*
// Brute force, O(N^2)
vector<int> LPS(string &s)
{
    int n = s.size();
    vector<int> lps(n, 0);
    for (int i = 1; i < n; i++)
    {
        for (int len = 1; len <= i; len++)
        {
            if (s.substr(0, len) == s.substr(i - len + 1, len))
                lps[i] = len;
        }
    }

    return lps;
}
*/