#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

long long power(long long base, long long n, long long MOD)
{
    long long ans = 1;
    while (n)
    {
        if (n & 1)
        {
            ans = ((ans * base) % MOD);
            n = n - 1;
        }

        else
        {
            n = n >> 1;
            base = ((base * base) % MOD);
        }
    }

    return ans;
}

int rabinKarp(string &s, string &pattern)
{
    int n1 = s.size();
    int n2 = pattern.size();
    int ans = 0;

    // compute patten hash
    long long patHash = 0;
    long long p = 1;
    for (char ch : pattern)
    {
        patHash = (patHash + (((ch - 'a' + 1) * p) % MOD)) % MOD;
        p = (p * 31) % MOD;
    }

    // compute hash for first window of s
    long long hash = 0;
    long long p1 = 1;
    long long p2 = 1;
    for (int i = 0; i < n2; i++)
    {
        hash = (hash + (((s[i] - 'a' + 1) * p2) % MOD)) % MOD;
        p2 = (p2 * 31) % MOD;
    }

    int left = 0, right = n2;
    if (hash == patHash)
        ans++;

    while (right < n1)
    {
        hash = (hash + (((s[right] - 'a' + 1) * p2) % MOD)) % MOD;
        hash = (hash - (((s[left] - 'a' + 1) * p1) % MOD) + MOD) % MOD;
        p2 = (p2 * 31) % MOD;
        p1 = (p1 * 31) % MOD;
        right++;
        left++;

        patHash = (patHash * 31) % MOD;

        if (patHash == hash)
            ans++;
    }

    return ans;
}

int main()
{
    string s = "aababacbabbadcbab";
    string pattern = "ab";
    cout << rabinKarp(s, pattern);
    return 0;
}