#include <bits/stdc++.h>
using namespace std;

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
    string newStr = pattern + "$" + s;
    vector<int> lps = LPS(newStr);

    vector<int> res;
    for (int i = n2 + 1; i < newStr.size(); i++)
    {
        if (lps[i] == n2)
            res.push_back(i - n2 + 1 - (n2 + 1));
    }

    return res;
}

int main()
{
    string s = "abababbababa";
    string pattern = "ab";

    vector<int> occurences = KMP(s, pattern);
    for (int it : occurences)
        cout << it << " ";

    return 0;
}

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14   ---> indices
// a b $ a b a b a b b a  b  a  b  a
// 0 0 0 1 2 1 2 1 2 0 1  2  1  2  1    ---> lps