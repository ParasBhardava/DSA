#include <bits/stdc++.h>
using namespace std;

// brute forcce : O(n^2)
// vector<int> Z_function(string &s)
// {
//     int n = s.size();
//     vector<int> z(n, 0);

//     for (int i = 1; i < n; i++)
//     {
//         while (i + z[i] < n && s[z[i]] == s[z[i] + i])
//             z[i]++;
//     }

//     return z;
// }

// Time Complexity : O(n)
vector<int> Z_function(string &s)
{
    int n = s.size(), l = 0, r = 0;
    vector<int> z(n, 0);
    for (int i = 1; i < n; i++)
    {
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);

        while (i + z[i] < n && s[z[i]] == s[z[i] + i])
            z[i]++;

        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

int main()
{
    string s = "abaabababaababa";
    vector<int> z = Z_function(s);
    for (char ch : s)
        cout << ch << " ";
    cout << "\n";

    for (int it : z)
        cout << it << " ";

    return 0;
}