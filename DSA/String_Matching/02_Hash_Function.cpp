#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

long long computeHash(string &s)
{
    // Here we take parime as 31
    long long p = 1;
    long long hash = 0;

    for (char ch : s)
    {
        hash = (hash + (((ch - 'a' + 1) * p) % MOD)) % MOD;
        p = (p * 31) % MOD;
    }

    return hash;
}

int main()
{
    string s = "abc";
    cout << computeHash(s) << "\n";
    return 0;
}

// abc = ((1 * 31^0) + (2 * 31^1) + (3 * 31^2)) % MOD