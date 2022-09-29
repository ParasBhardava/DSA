#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int countUnique(string &s)
{
    int n = s.size();
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        long long hash = 0;
        long long p = 1;
        for (int j = i; j < n; j++)
        {
            hash = (hash + (((s[j] - 'a' + 1) * p) % MOD)) % MOD;
            st.insert(hash);
            p = (p * 31) % MOD;
        }
    }

    return st.size();
}

int main()
{
    string s = "abc";
    cout << countUnique(s);
    return 0;
}