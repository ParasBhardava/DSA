// Problem Link : https://codeforces.com/problemset/problem/271/D

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main()
{
    // input
    string s = "ababab";
    vector<int> goodBad = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int k = 1;

    // processing
    int n = s.size();
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        string temp = "";
        int countBad = 0;
        long long p = 1;
        long long hash = 0;

        for (int j = i; j < n; j++)
        {
            temp.push_back(s[j]);
            if (goodBad[s[j] - 'a'] == 1)
                countBad++;

            if (countBad > k)
                break;

            hash = ((hash + ((s[j] - 'a' + 1) * p) % MOD) % MOD);
            p = (p * 31) % MOD;
            st.insert(hash);
        }
    }

    cout << st.size() << "\n";

    return 0;
}
