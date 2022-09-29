#include <bits/stdc++.h>
using namespace std;

// IN bottomup(tabulation) we can not write base condition like this
// if (i < 0 || j < 0) return 0;
// because in array there is no negative indices
// so we shit every index by  +1;
// so base case become like this
// (i == 0 || j == 0) return 0;

int LCS(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m + 1, 0);

    for (int j = 0; j <= m; j++)
        prev[j] = 0;

    for (int i = 1; i <= n; i++)
    {
        int ele = prev[0];
        for (int j = 1; j <= m; j++)
        {
            int temp = prev[j];

            if (s1[i - 1] == s2[j - 1])
                prev[j] = 1 + ele;

            else
                prev[j] = max(prev[j - 1], prev[j]);

            // cout << prev[j] << " ";

            ele = temp;
        }
        cout << "\n";
    }

    return prev[m];
}

int main()
{
    string s1 = "abcdgh";
    string s2 = "abedfhr";

    cout << LCS(s1, s2) << "\n";
    return 0;
}